#ifndef				GGJ_WINDOW_H_
# define			GGJ_WINDOW_H_

#include <SFML/Graphics.hpp>

namespace GGJ
{
	class		Window
	{
	public:
		Window(unsigned int height = 800, unsigned int width = 600,
				const std::string& title = "GGJ Project");
		void		close(void);
		
		// Getters
		unsigned int			getHeight(void) const;
		unsigned int			getWidth(void) const;

	private:
		sf::RenderWindow		_window;
		std::string				_title;
		unsigned int			_height;
		unsigned int			_width;
		
	};
};

#endif /* GGJ_WINDOW_H_ */