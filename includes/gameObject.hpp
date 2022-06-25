#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP
#include "mathGame.hpp"
#include "core/components.hpp"
#include <vector>

class GameObject{
private:
    Vector2 position;
    Vector2 size;

    std::vector<Component*> components;

public:
    GameObject(Vector2 position, Vector2 size);

    void render(SDL_Renderer *renderer);
    void addComponent(Component *component);
};

GameObject::GameObject(Vector2 position, Vector2 size){
    this->position = position;
    this->size = size;
}

void GameObject::addComponent(Component *component){
    component->position = position;
    component->size = size;
    components.push_back(component);
}

void GameObject::render(SDL_Renderer *renderer){
    for(auto& c : components){
        c->render(renderer);
    }
}


#endif