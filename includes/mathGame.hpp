#pragma once
#include "SDL2/SDL.h"

/*
* Struct for create Vector with two-dimensions
*/
struct Vector2{
    int x;
    int y;
    Vector2 operator+(Vector2 vector){
        x += vector.x;
        y += vector.y;
    }
    Vector2 operator+=(Vector2 vector){
        x += vector.x;
        y += vector.y;
    }
};

/*
* Struct for create Color
*/
struct Color{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};