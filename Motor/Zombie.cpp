#include "Zombie.h"

Zombie::Zombie() {}

Zombie::~Zombie() {}

void Zombie::init(float speed, glm::vec2 position, GLuint textureID) {
    this->speed = speed;
    this->position = position;
    this->textureID = textureID;
}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies) {
    moveRandomly();  // Mover aleatoriamente en cada actualización
    collideWithLevel(levelData);  // Asegurarse de que los zombis no salgan del área del mapa
}

void Zombie::draw(SpriteBatch& spriteBatch) {
    const glm::vec4 destRect(position.x, position.y, AGENT_WIDTH, AGENT_WIDTH);
    const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
    spriteBatch.draw(destRect, uvRect, textureID, 0.0f, Color(0, 255, 0, 255));
}

void Zombie::moveRandomly() {
    // Generar un movimiento aleatorio en las direcciones x e y
    position.x += (rand() % 3 - 1) * speed;  // Valor aleatorio entre -1 y 1 multiplicado por la velocidad
    position.y += (rand() % 3 - 1) * speed;  // Lo mismo para la dirección y
}
