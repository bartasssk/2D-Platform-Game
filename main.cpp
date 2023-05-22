#include "Player.h"
#include "Game.h"
#include "Obiekty.h"
using namespace std;


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;

	Uint32 FrameStart;
	int FrameTime;
	
	Game* game = nullptr;
	game = new Game();
	game->init("Rise from the ashes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	while (game->running()) {
		FrameStart = SDL_GetTicks();
		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
		game->events();
		game->update();
		game->render();
	}
	game->clean();
	delete game;

	
	return 0;
}

