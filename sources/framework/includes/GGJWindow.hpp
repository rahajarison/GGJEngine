#ifndef				GGJ_WINDOW_H_
# define			GGJ_WINDOW_H_

#include <SFML/Graphics.hpp>

namespace GGJ
{
	class		Window
	{
	public:
		Window(unsigned int height = 1024, unsigned int width = 1024,
				const std::string& title = "Growing Leo");
		void		close(void);
		
		// Getters
		unsigned int			getHeight(void) const;
		unsigned int			getWidth(void) const;
		void					clear(void);
		void					display(void);
		sf::RenderWindow&		accessRenderWindow(void);

	private:
		sf::RenderWindow		_window;
		std::string				_title;
		unsigned int			_height;
		unsigned int			_width;
	
	public:
		static const unsigned int	MAX_FPS;
	};
};

#endif /* GGJ_WINDOW_H_ */