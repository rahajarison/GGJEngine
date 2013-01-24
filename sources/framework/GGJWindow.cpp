#include		<GGJWindow.hpp>

namespace GGJ
{
Window::Window(unsigned int height, unsigned int width,
				const std::string& title) :
_window(sf::VideoMode(height, width, 32), title), _title(title),
_height(height), _width(width)
{
}

void			Window::close(void)
{
	_window.Close();
}

unsigned int	Window::getHeight(void) const
{	return (_height);	}
unsigned int	Window::getWidth(void) const
{	return (_width);	}

};