#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "GLS_Program.h"
#include "Window.h"
#include "Camera2D.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Human.h"
#include "Zombie.h"
#include "SpriteBatch.h"

// Agregar un vector para almacenar los zombis
#include "Zombie.h"

enum class GameState {
	PLAY, EXIT
};

class MainGame
{
private:
	// Otras variables miembro existentes
	vector<Zombie*> zombies;  // Vector para almacenar zombis
	int width;
	int height;
	SpriteBatch spriteBatch;
	SpriteBatch hudBatch;
	vector<Level*> levels;
	vector<Human*> humans;
	vector<Zombie*> zombies;
	Player* player;
	double alphaReduce;
	double alphaReduceTotal;
	int currentLevel;
	Window window;
	GLS_Program program;
	Sprite sprite;
	Camera2D camera2D;
	InputManager inputManager;
	void init();
	void initLevel();
	void processInput();
	void initShaders();
	void handleInput();
	void updateElements();
	void createBullet();
	// Otros métodos miembro existentes
	void initZombies();  // Método para inicializar zombis
public:
	MainGame();
	~MainGame();
	GameState gameState;

	void run();
	void draw();
	void drawHud();
	void update();
	void reset();
};

