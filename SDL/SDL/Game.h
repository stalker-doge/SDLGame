#pragma once
#include <SDL.h>
#include "InputManager.h"
#include "Visualisation.h"
#include "Player.h"
#include <vector>
class Game
{
public:
	static Game* Instance();
	~Game();
	void Update();
	void Render();
	bool IsGameRunning();
	void Initialise();
	void Uninitialise();
	void StopGame();
	void RestartGame();
	Entity* CheckCollisions();
	bool TestCollision(Entity* player, Entity* block);
private:
	Game();
	Game(const Game&) = delete;
	static Game* s_instance;
	SDL_Window* gameWindow;
	SDL_Renderer* gameRender;
	int rgb[3];
	InputManager* inputManager;
	Visualisation* m_visualisation;
	bool running;
	Player* m_player;
	Entity* m_block[3];
	Entity* m_spikeBlocks[5];
	Entity* m_star;
	std::vector<Entity*> m_entities;
};

