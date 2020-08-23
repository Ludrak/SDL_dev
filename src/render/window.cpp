
#include "window.hpp"

//		WINDOW - Destructor
//		- Destroys the window object.
void		Window::~Window()
{
	SDL_DestroyWindow(this.window);
}

//		CREATE_WINDOW
//		- Creates a new window.
int		Window::create_window(int x, int y, std::string title)
{
	this.window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		x,
		y,
		SDL_WINDOW_OPENGL
	);
	if (this.window == nullptr)
	{
		SDL_Log("Unable to create window : %s", SDL_GetError());
		return (-1);
	}
	SDL_Log("Sucessfully created window");
	return (0);
}

//		SET_RENDERER
//		- Sets the renderer of the window
int		Window::set_renderer(Renderer &renderer)
{
	if (renderer != nullptr)
	{
		this.renderer = renderer;
		return (0);
	}
	SDL_Log("Unable to set renderer : trying to set window renderer to null.");
	return (-1);
}

//		GET_RENDERER
//		- Returns the current renderer of the window;
Renderer	get_renderer()
{
	return (this.renderer);
}

//		GET_WINDOW
//		- Returns the current window
SDL_Window	get_window()
{
	return (*this.window);
}
