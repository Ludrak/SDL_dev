

#ifndef WINDOW_H
# define WINDOW_H

# ifndef SDL2
#  include "SDL.h"
#  define SDL2
# endif

# include "renderer.hpp"

class Window
{
	private:
		SDL_Window	*window;
		Renderer	*renderer;
	public:
		int		create_window(int size_x, int size_y, const char *title);
		int		create_window(int size_x, int size_y);

		int		set_renderer(Renderer *renderer);
		Renderer	*get_renderer();

		SDL_Window	*get_window();
};

#endif

