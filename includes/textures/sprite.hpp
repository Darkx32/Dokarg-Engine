#ifndef _SPRITE_HPP
#define _SPRITE_HPP
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "textures/core.hpp"
#include "core/components.hpp"


class Sprite : public Component{
private:
    std::string file;
    SDL_Texture *texture;
    SDL_Surface *surface;

public:
    Sprite(std::string file){
        surface = IMG_Load(file.c_str());
        texture = nullptr;
    }

    ~Sprite(){
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    void render(SDL_Renderer *renderer){
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect rect{0, 0};
        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        SDL_Rect pos{position.x, position.y, rect.w, rect.h};
        SDL_RenderCopy(renderer, texture, &rect, &pos);
        SDL_DestroyTexture(texture);
    }
};

#endif