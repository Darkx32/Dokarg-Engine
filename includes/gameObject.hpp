#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP
#include "mathGame.hpp"
#include "core/components.hpp"
#include <vector>

class GameObject{
private:
    Vector2 position;

    std::vector<Component*> components;

public:
    GameObject(Vector2 position);

    void render(SDL_Renderer *renderer);
    void addComponent(Component *component);
};

GameObject::GameObject(Vector2 position){
    this->position = position;
}

void GameObject::addComponent(Component *component){
    component->position = position;
    components.push_back(component);
}

void GameObject::render(SDL_Renderer *renderer){
    for(auto& c : components){
        c->render(renderer);
    }
}


#endif