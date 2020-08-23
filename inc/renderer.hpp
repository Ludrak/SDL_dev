
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
		int	create_renderer(SDL_Window *window);

		void	clear(int r, int g, int b);
		void	clearw();

		void	draw();
		void	apply();
		
		//COLOR
		void	set_color(int r, int g, int b);
		void	set_color(int r, int g, int b, int a);
		void	set_color(int l);
		void	set_color(int l, int a);	
	
		//RECTANLGE
		void	draw_rect(int x, int y, int w, int h);
		void	fill_rect(int x, int y, int w, int h);
};

#endif
