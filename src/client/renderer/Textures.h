#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <cstdint>
#include <map>
#include "../../Options.h"
#include "../../AppPlatform.h"
#include "TextureData.h"
#ifdef USE_DESKTOP_GL
#include <glad/gl.h>
#else
#include <GLES/gl.h>
#endif
#include "DynamicTexture.h"

class Textures {
public:
	static uint32_t textureChanges;
	static uint8_t MIPMAP;
    std::map<std::string, GLuint> textureNameMap;
    std::map<GLuint, TextureData> textureDataMap;
    Options *options;
    AppPlatform *platform;
    bool noRepeat;
    bool forceLinearFilter;
    uint32_t lastLoadedTextureId;
    std::vector<DynamicTexture *> dynamicTextures;
	
	Textures(Options *options, AppPlatform *platform);

	GLuint assignTexture(const std::string& name, const TextureData& data);

	void addDynamicTexture(DynamicTexture *texture);

	TextureData *getTemporaryTextureData(GLuint textureId);

	int32_t smoothBlend(int32_t u, int32_t v);

	void clear();

	int32_t crispBlend(int32_t u, int32_t v);

	GLuint loadAndBindTexture(const std::string& name);

	void tick(bool doBind);

	void reloadAll();

	GLuint loadTexture(const std::string& name, bool alpha);

	static bool isTextureIdValid(GLuint textureId);

	void bind(GLuint textureId);
};

#endif
