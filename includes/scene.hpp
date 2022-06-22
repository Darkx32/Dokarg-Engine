#ifndef _SCENE_HPP
#define _SCENE_HPP
#include <vector>
#include "gameObject.hpp"
#include "SDL2/SDL.h"
#include <iostream>
#include <string>

/*
* Class for create Scene
*/
class Scene{
private:
    SDL_Renderer *renderer;
    SDL_Event event;
    Color background;

    std::string name;
    std::vector<GameObject*> gameObjects;

public:
    Scene(std::string name, Color background);
    Scene() = default;

    void createRenderer(SDL_Window *window);
    void render();
    void addGameObject(GameObject *gameObject);
    SDL_Event *getEvent() {return &event;}
    void destroy();
};

Scene::Scene(std::string name, Color background){
    this->name = name;
    this->background = background;
}

void Scene::createRenderer(SDL_Window *window){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(renderer == NULL){
        std::cerr << "Error in create renderer in " << name << std::endl;
        exit(-1);
    }
}

void Scene::addGameObject(GameObject *gameObject){
    gameObjects.push_back(gameObject);
}

void Scene::render(){
    SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);
    SDL_RenderClear(renderer);
    if(!gameObjects.empty())
        for(auto& gj : gameObjects){
            gj->render(renderer);
        }
    SDL_RenderPresent(renderer);
}

void Scene::destroy(){
    SDL_DestroyRenderer(renderer);
}

#endif