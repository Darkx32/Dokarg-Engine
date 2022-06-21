#ifndef _RECT_HPP
#define _RECT_HPP
#include "mathGame.hpp"
#include "core/components.hpp"
#include <iostream>

class Rect : public Component{
private:
    Vector2 position;
    Vector2 size;
    Color background;

public:
    Rect(Vector2 size, Color background);

    void render(SDL_Renderer *renderer);
    void setPosition(Vector2 position);
};

void Rect::render(SDL_Renderer *renderer){
    SDL_Rect *rect = new SDL_Rect{position.x, position.y, size.x, size.y};
    SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
    SDL_RenderFillRect(renderer, rect);
    delete rect;
}

Rect::Rect(Vector2 size, Color background){
    this->size = size;
    this->background = background;
}

void Rect::setPosition(Vector2 position){
    this->position = position;
}

#endif