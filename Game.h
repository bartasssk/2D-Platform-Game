#pragma once
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Collider.h"
#include "LevelManager.h"

/**
 * @brief Class responsible for game loop, events, rendering, etc.
*/
class Game {
private:
	/**
	 * @brief SDL_Window
	*/
	SDL_Window* window;
	/**
	 * @brief SDL_Renderer
	*/
	SDL_Renderer* renderer;
	/**
	 * @brief The player.
	*/
	Player* player = nullptr;
	/**
	 * @brief Level Manager.
	*/
	LevelManager* levelmanager;
	/**
	 * @brief Vector of objects.
	*/
	std::vector <Object> objects;
	/**
	 * @brief Vector of enemies.
	*/
	std::vector <Enemy> enemies;
	/**
	 * @brief Collision manager.
	*/
	Collider* collider;
	/**
	 * @brief Font with size 64.
	*/
	TTF_Font* font1;
	/**
	 * @brief Font with size 192.
	*/
	TTF_Font* font2;
	/**
	 * @brief Font with size 20.
	*/
	TTF_Font* font3;
	/**
	 * @brief Font with size 128.
	*/
	TTF_Font* font4;
	/**
	 * @brief Color white.
	*/
	SDL_Color text_color{};
	/**
	 * @brief Variable that tells if user started the game.
	*/
	bool started;
	/**
	 * @brief Variable that tells if user finished the game.
	*/
	bool ended;
public:
	/**
	 * @brief Constructor.
	*/
	Game();
	/**
	 * @brief Destructor.
	*/
	~Game();
	/**
	 * @brief Initializer of the game.
	*/
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	/**
	 * @brief Handles events.
	*/
	void events(SDL_Event& event);
	/**
	 * @brief Function responsible for start of the game.
	*/
	void start(SDL_Event& event);
	/**
	 * @brief Responsible for any changes like movement, collision, etc.
	*/
	void update();
	/**
	 * @brief Renders everything to the screen.
	*/
	void render();
	/**
	 * @brief Shows player's Health Points on the screen.
	*/
	void showPlayerHP();
	/**
	 * @brief Shows that you died.
	*/
	void death();
	/**
	 * @brief Updates levels and end of the game.
	*/
	void progress();
	/**
	 * @brief Cleans the game after the loop ends.
	*/
	void clean();
	/**
	 * @brief Is responsible for closing the game.
	*/
	bool running(SDL_Event& event);
	/**
	 * @brief Loads texture.
	*/
	SDL_Texture* loadTex(const char* FilePath);
};