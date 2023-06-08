#include "Game.h"
using namespace std;


int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;
	const int SCREEN_WIDTH = 1600;
	const int SCREEN_HEIGHT = 720;

	Uint32 FrameStart;
	int FrameTime;
	
	Game game;
	game.init("Rise from the ashes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	SDL_Event event{};
	while (1) {
		FrameStart = SDL_GetTicks();
		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime) {
			SDL_Delay(FrameDelay - FrameTime);
		}
		SDL_PollEvent(&event);
		if (!game.running(event)) {
			break;
		}
		game.events(event);
		game.update();
		game.render();
	}
	game.clean();
	
	return 0;
}

