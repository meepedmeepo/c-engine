#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include "../rendering/ctexture.h"
#include <map>
#include <string>

class TextureManager{
    public:
    TextureManager();
    ~TextureManager();

    void loadTexture();

    private:
    std::map<std::string, CTexture> mTextures;
};



#endif
