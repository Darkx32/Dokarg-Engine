#ifndef _RECT_HPP
#define _RECT_HPP
#include "mathGame.hpp"
#include "core/components.hpp"
#include <iostream>

/*
* Class for create component rect into GameObject
*/
class Rect : public Component{
private:
    Color background;

public:
    Rect(Color background);

    void render(SDL_Renderer *renderer);
};

void Rect::render(SDL_Renderer *renderer){
    SDL_Rect *rect = new SDL_Rect{position.x, position.y, size.x, size.y};
    SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
    SDL_RenderFillRect(renderer, rect);
    delete rect;
}

Rect::Rect(Color background){
    this->background = background;
}

#endif