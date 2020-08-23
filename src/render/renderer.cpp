

#include "renderer.hpp"

//void	Renderer::~Renderer()
//{
//	SDL_DestroyRenderer(this.renderer);
//}

//	CREATE_RENDERER
//	- Creates a new renderer for a specified window.
int	Renderer::create_renderer(SDL_Window *window)
{
	SDL_Log("Setting up renderer...");
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (this->renderer == nullptr)
	{
		SDL_Log("Unable to create renderer : %s", SDL_GetError());
		return (-1);
	}
	SDL_Log("Sucessfully initialised renderer.");
	return (0);
}

//	CLEAR
//	- Clears the screen. (note: you need to call the apply() function to actually clear the screen instantly)
void	Renderer::clear(int r, int g, int b)
{
	SDL_SetRenderDrawColor(this->renderer, r, g, b, 255);
	SDL_RenderClear(this->renderer);
}

//	CLEARW
//	- Similar to clear() except it always clears the screen with white and it automaticaly calls apply() for update
void	Renderer::clearw()
{
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

//	DRAW
//	- Called each frame, everything inside this will be drawn on screen.
void	Renderer::draw()
{

}

//	APPLY
//	- Apply every components of the renderer that was set before (automatically called after draw())
void	Renderer::apply()
{
	SDL_RenderPresent(this->renderer);
}

