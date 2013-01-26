#include		<GGJWindow.hpp>

namespace GGJ
{
const unsigned int Window::MAX_FPS = 60;
Window::Window(unsigned int height, unsigned int width,
				const std::string& title) :
_window(sf::VideoMode(height, width, 32), title), _title(title),
_height(height), _width(width)
{
	_window.SetFramerateLimit(Window::MAX_FPS);
}

void			Window::close(void)				{	_window.Close();	}
void			Window::clear(void) 			{	_window.Clear();	}
void			Window::display(void) 			{	_window.Display();	}
unsigned int	Window::getHeight(void) const	{	return (_height);	}
unsigned int	Window::getWidth(void) const	{	return (_width);	}
sf::RenderWindow& Window::accessRenderWindow()	{	return (_window);	}

};