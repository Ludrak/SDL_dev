
#ifndef RENDERER_H
# define RENDERER_H

#ifndef SDL2_H
# include "SDL.h"
# define SLD2_H
#endif

class Renderer
{
	private:
		SDL_Renderer	*renderer;
	public:
		int	create_renderer(SDL_Window window);

		void	clear(int r, int g, int b);
		void	clearw();

		void	draw();
		void	apply();
};

#endif
