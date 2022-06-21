#ifndef _WINDOW_HPP
#define _WINDOW_HPP
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <string>
#include "scene.hpp"

#define WINDOW_CENTERED SDL_WINDOWPOS_CENTERED

class Window
{
private:
    SDL_Window *window;

    Scene *scene;
    std::string title;
    int x;
    int y;
    int width;
    int height;

    void init();
public:
    Window(std::string title, int x, int y, int width, int height, bool fullscreen);
    ~Window();
    bool isRunning;

    void stop();
    void close();
    void handleEvent();
    void render();
    void setScene(Scene *scene);
};

Window::~Window()
{
    close();
}

Window::Window(std::string title, int x, int y, int width, int height, bool fullscreen)
{
    this->init();
    int windowsFlags = SDL_WINDOW_SHOWN;
    if(fullscreen){
        windowsFlags = windowsFlags|SDL_WINDOW_FULLSCREEN;
    }
    window = SDL_CreateWindow(title.c_str(), x, y, width, height, windowsFlags);
    if(window == NULL){
        std::cerr << "Error in start window: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    isRunning = false;
    scene = NULL;
}

void Window::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cerr << "Error in init SDL library: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    if(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG|IMG_INIT_TIF|IMG_INIT_WEBP) < 0){
        std::cerr << "Error in init IMG library: " << IMG_GetError() << std::endl;
        exit(-1);
    }
    if(TTF_Init() < 0){
        std::cerr << "Error in init TTF library: " << TTF_GetError() << std::endl;
        exit(-1);
    }
}

void Window::handleEvent(){
    while(SDL_PollEvent(scene->getEvent())){
        switch (scene->getEvent()->type)
        {
        case SDL_QUIT:
            stop();
            break;
        
        default:
            break;
        }
    }
}


void Window::setScene(Scene *scene){
    if(this->scene != NULL){
        scene->destroy();
        scene = nullptr;
    }
    scene->createRenderer(window);
    this->scene = scene;
    isRunning = true;
}

void Window::render(){
    scene->render();
    SDL_Delay(1000/60);
}

void Window::stop(){
    isRunning = false;
}

void Window::close(){
    scene->destroy();
    scene = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

#endif