#include "Textures.h"
#include <cstring>

uint32_t Textures::textureChanges = 0;
uint8_t Textures::MIPMAP = 0;

Textures::Textures(Options *options, AppPlatform *platform) {
    this->options = options;
    this->platform = platform;
    this->noRepeat = false;
    this->forceLinearFilter = false;
    this->lastLoadedTextureId = -1;
}

GLuint Textures::assignTexture(const std::string& name, const TextureData& data) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    this->bind(textureId);
    if (Textures::MIPMAP) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    if (this->forceLinearFilter) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    if (this->noRepeat) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    if (data.type >= 0 && data.type < 4) {
        GLenum format = data.alpha ? GL_RGBA : GL_RGB;
        switch (data.type) {
        case 0:
            glTexImage2D(GL_TEXTURE_2D, 0, format, data.width, data.height, 0, format, GL_UNSIGNED_BYTE, (const GLvoid *)data.pixels);
            break;
        case 1:
            glTexImage2D(GL_TEXTURE_2D, 0, format, data.width, data.height, 0, format, GL_UNSIGNED_SHORT_5_6_5, (const GLvoid *)data.pixels);
            break;
        case 3:
            glTexImage2D(GL_TEXTURE_2D, 0, format, data.width, data.height, 0, format, GL_UNSIGNED_SHORT_4_4_4_4, (const GLvoid *)data.pixels);
            break;
        case 2:
            glTexImage2D(GL_TEXTURE_2D, 0, format, data.width, data.height, 0, format, GL_UNSIGNED_SHORT_5_5_5_1, (const GLvoid *)data.pixels);
            break;     
        }
    }
    this->textureNameMap[name] = textureId;
    this->textureDataMap[textureId] = data;
    return textureId;
}

void Textures::addDynamicTexture(DynamicTexture *texture) {
    this->dynamicTextures.push_back(texture);
    texture->tick();
}

TextureData *Textures::getTemporaryTextureData(GLuint textureId) {
    std::map<GLuint, TextureData>::iterator it = this->textureDataMap.find(textureId);
    if (it == this->textureDataMap.end()) {
        return NULL;
    }
    return &it->second;
}

int32_t Textures::smoothBlend(int32_t u, int32_t v) {
    return (((v & 0xFEFEFE) + (u & 0xFEFEFE)) >> 1) + ((int32_t)(((uint32_t)v >> 24) + ((uint32_t)u >> 24)) >> 1 << 24);
}

void Textures::clear() {
    std::map<std::string, GLuint>::iterator tnit = this->textureNameMap.begin();
    while (true) {
        if (tnit == this->textureNameMap.end()) {
            break;
        }
        if (tnit->second != -1) {
            glDeleteTextures(1, &tnit->second);
        }
        ++tnit;
    }
    std::map<GLuint, TextureData>::iterator tdit = this->textureDataMap.begin();
    while (true) {
        if (tdit == this->textureDataMap.end()) {
            break;
        }
        if (tdit->second.keepBufferData != 1) {
            if (tdit->second.pixels != NULL) {
                operator delete[](tdit->second.pixels);
            }
        }
        ++tdit;
    }
    this->textureNameMap.clear();
    this->textureDataMap.clear();
    this->lastLoadedTextureId = -1;
}

int32_t Textures::crispBlend(int32_t u, int32_t v) {
    uint32_t uu = (uint32_t)u >> 24;
    uint32_t vv = (uint32_t)v >> 24;
    int32_t alpha = 255;
    if (uu + vv == 0) {
        uu = 1;
        vv = 1;
        alpha = 0;
    }
    int32_t r = (uu * (u >> 16 & 255) + vv * (v >> 16 & 255)) / (vv + uu);
    int32_t g = (uu * (u >> 8 & 255) + vv * (v >> 8 & 255)) / (vv + uu);
    int32_t b = (uu * (u & 255) + vv * (v & 255)) / (vv + uu);
    return alpha << 24 | r << 16 | g << 8 | b;
}

GLuint Textures::loadAndBindTexture(const std::string& name) {
    GLuint textureId = this->loadTexture(name, true);
    if (textureId != -1) {
        this->bind(textureId);
    }
    return textureId;
}

void Textures::tick(bool doBind) {
    for (int i = 0; i < this->dynamicTextures.size(); ++i) {
        DynamicTexture *texture = this->dynamicTextures[i];
        texture->tick();
        if (doBind) {
            texture->bindTexture(this);
            for (int32_t tileX = 0; tileX < texture->tileCount; ++tileX) {
                for (int32_t tileY = 0; tileY < texture->tileCount; ++tileY) {
                    glTexSubImage2D(GL_TEXTURE_2D, 0, 16 * (tileX + texture->tileSideSize % 16), 16 * (tileY + texture->tileSideSize / 16), 16, 16, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
                }
            }
        }
    }
}

void Textures::reloadAll() {}

GLuint Textures::loadTexture(const std::string& name, bool alpha) {
    std::map<std::string, GLuint>::iterator it = this->textureNameMap.find(name);
    if (it != this->textureNameMap.end()) {
        return it->second;
    }
    TextureData data = this->platform->loadTexture(name, alpha);
    return this->assignTexture(name, data);
}

bool Textures::isTextureIdValid(GLuint textureId) {
    return textureId != -1;
}

void Textures::bind(GLuint textureId) {
    if (textureId != -1 && this->lastLoadedTextureId != textureId) {
        glBindTexture(GL_TEXTURE_2D, textureId);
        this->lastLoadedTextureId = textureId;
        ++Textures::textureChanges;
    }
}