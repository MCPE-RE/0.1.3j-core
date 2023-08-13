#include "Font.h"
#include <cstring>

Font::Font(Options *options, const std::string& textureName, Textures *textures) {
	this->textureName = textureName;
	this->textures = textures;
	this->options = options;
	this->init(this->options);
}

void Font::init(Options *opt) {
    GLuint textureId = this->textures->loadTexture(this->textureName, true);
    TextureData *data = this->textures->getTemporaryTextureData(textureId);
    if (data != NULL) {
        for (int32_t i = 0; i < 256; ++i) {
            int32_t xt = i % 16;
            int32_t yt = i / 16;
            int32_t x = 7;
            for (bool emptyColumn = false; x >= 0; --x) {
                int32_t xPixel = xt * 8 + x;
                emptyColumn = true;
                for (int32_t y = 0; (y < 8) && emptyColumn; ++y) {
                    int32_t yPixel = (yt * 8 + y) * data->width;
                    uint8_t pixel = data->pixels[4 * (xPixel + yPixel)];
                    if (pixel) {
                        emptyColumn = false;
                    }
                }
                if (!emptyColumn) {
                    break;
                }
            }
            if (i == 32) {
                x = 2;
            }
            this->charWidthsInt[i] = x + 2;
            this->charWidthsFloat[i] = (float)this->charWidthsInt[i];
        }
    }
}

void Font::buildChar(uint8_t c, float x, float y) {
	float bx = (float)(8 * (c & 0xF));
	float by = (float)(8 * (c >> 4));

	Tesselator::instance.vertexUV(x, y + 7.99f, 0.0f, (bx / 128.0f) + 0.0f, ((by + 7.99f) / 128.0f) + 0.0f);
	Tesselator::instance.vertexUV(x + 7.99f, y + 7.99f, 0.0f, ((bx + 7.99f) / 128.0f) + 0.0f, ((by + 7.99f) / 128.0f) + 0.0f);
	Tesselator::instance.vertexUV(x + 7.99f, y, 0.0f, ((bx + 7.99f) / 128.0f) + 0.0f, (by / 128.0f) + 0.0f);
	Tesselator::instance.vertexUV(x, y, 0.0f, (bx / 128.0f) + 0.0f, (by / 128.0f) + 0.0f);
}

void Font::drawSlow(const std::string& text, int32_t x, int32_t y, int32_t colorHash, bool darken) {
    if (!text.empty()) {
        if (darken) {
            colorHash = (colorHash & 0xFF000000) + ((colorHash & 0xFCFCFC) >> 2);
        }
        this->textures->loadAndBindTexture(this->textureName);
        float a = (float)((colorHash >> 24) & 0xff) / 255.0f;
        if (a == 0.0f) {
            a = 1.0f;
        }
        float r = (float)((colorHash >> 16) & 0xff) / 255.0f;
        float g = (float)((colorHash >> 8) & 0xff) / 255.0f;
        float b = (float)(colorHash & 0xff) / 255.0f;
        glColor4f(r, g, b, a);
        glPushMatrix();
        Tesselator::instance.begin();
        glTranslatef(x, y, 0.0f);
        float fx = 0.0f;
        float fy = 0.0f;
        for (int i = 0; i < text.length(); ++i) {
            uint8_t c = text[i];
            if (c == '\n') {
                fx = 0.0f;
                fy += 12.0f;
            } else {
                this->buildChar(c, fx, fy);
                fx += this->charWidthsFloat[c];
            }
        }
        Tesselator::instance.draw();
        glPopMatrix();
    }
}

void Font::draw(const std::string& text, int32_t x, int32_t y, int32_t colorHash, bool darken) {
    this->drawSlow(text, x, y, colorHash, darken);
}

void Font::draw(const std::string& text, int32_t x, int32_t y, int32_t colorHash) {
    this->draw(text, x, y, colorHash, false);
}

void Font::drawShadow(const std::string& text, int32_t x, int32_t y, int32_t colorHash) {
    this->draw(text, x + 1, y + 1, colorHash, true);
    this->draw(text, x, y, colorHash);
}

void Font::onGraphicsReset() {
    this->init(this->options);
}

std::string Font::sanitize(const std::string& text) {
    std::string temp(text.length() + 1, 0);
    int32_t ti = 0;
    for (int32_t i = 0; i < text.length(); ++i) {
        if (text[i] == 167) {
            ++i;
        } else {
            temp[ti++] = text[i];
        }
    }
    return temp.erase(ti);
}

int32_t Font::width(const std::string& text) {
    int32_t temp = 0;
    int32_t size = 0;
    for (int32_t i = 0; i < text.length(); ++i) {
        uint8_t c = text[i];
        if (c == 167) {
            ++i;
        } else if (c == '\n') {
            size = std::max(size, temp);
        } else {
            size += this->charWidthsInt[c];
        }
    }
    return std::max(size, temp);
}

int32_t Font::height(const std::string& text) {
    int32_t size = 0;
    for (int32_t i = 0; i < text.length(); ++i) {
        if (text[i] == '\n') {
            size += 12;
        }
    }
    return size;
}

void Font::drawWordWrap(const std::string& text, int32_t x, int32_t y, int32_t maxLineWidth, int32_t colorHash) {
    char *dest = new char[text.length() + 1];
    strncpy(dest, text.c_str(), text.length());
    dest[text.length()] = '\0';
    char *token = strtok(dest, " \n\t\r");
    std::vector<std::string> wordArray;
    while (token != NULL) {
        wordArray.push_back(token);
        token = strtok(NULL, " \n\t\r");
    }
    if (dest != NULL) {
        delete[] dest;
    }
    int wordIndex = 0;
    while (wordIndex < wordArray.size()) {
        std::string text = wordArray[wordIndex++] + " ";
        while (true) {
            bool noWrap = false;
            if (wordIndex < wordArray.size()) {
                if (this->width(text + wordArray[wordIndex]) < maxLineWidth) {
                    noWrap = true; 
                }
            }
            if (!noWrap) {
                break;
            }
            text += wordArray[wordIndex++] + " ";
        }
        this->draw(text, x, y, colorHash);
        y += 8;
    }
}
