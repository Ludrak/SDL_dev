
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
	window.set_renderer(&renderer);
	renderer.clear(100, 149, 237);

	renderer.set_color(255, 0, 0);
	renderer.fill_rect(0, 0, 100, 100);
	renderer.apply();
	
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
