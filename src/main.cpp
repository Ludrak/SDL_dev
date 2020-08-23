
#include <iostream>
#include "window.hpp"

int	main(int ac, char **av)
{

	//SDL2 init
	SDL_Init(SDL_INIT_VIDEO);

	//Window setup

	Window	window;
	window.create_window(1280, 720, "First SDL Window");

	//Renderer setup
	Renderer renderer = Renderer();
	renderer.create_renderer(window.get_window());
	window.set_renderer(renderer);
	renderer.clear(100, 149, 237);
	renderer.apply();


	//Render Rectangle Setup
//	SDL_Rect	rect;
//	rect.x = 0;
//	rect.y = 0;
//	rect.w = 100;
//	rect.h = 200;
//	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//	SDL_RenderFillRect(renderer, &rect);

	//show renderer components
//	SDL_RenderPresent(renderer);

	//Game Loop
	while (1)
	{
		SDL_Event	event;

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				SDL_Log("Closing window : quit event recieved.");
				break;
			}
		}
	}

	//Destroy all
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
