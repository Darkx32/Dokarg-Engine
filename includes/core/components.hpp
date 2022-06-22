#pragma once
#include "SDL2/SDL.h"
#include "mathGame.hpp"

/*
* Class component for GameObjects
*/
class Component{
public:
    virtual void render(SDL_Renderer *renderer) {}
    virtual void setPosition(Vector2 position) {}
};