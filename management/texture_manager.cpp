#include "texture_manager.h"
#include <cstdio>

void TextureManager::loadTexture(){
    if(auto res = mTextures.find("cum"); res != mTextures.end()){
        printf("FOUND!");
    }
}
