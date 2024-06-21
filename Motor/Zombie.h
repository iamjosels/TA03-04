#pragma once
#include "Agent.h"

class Zombie : public Agent {
public:
    Zombie();
    ~Zombie();

    void init(float speed, glm::vec2 position, GLuint textureID);
    void update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies);
    void draw(SpriteBatch& spriteBatch);

private:
    GLuint textureID;
    void moveRandomly();  // Método para mover aleatoriamente
};
