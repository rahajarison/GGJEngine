#ifndef				GGJ_MENU_H_
# define			GGJ_MENU_H_

#include		<vector>
#include		<SFML/Graphics.hpp>

namespace	GGJ
{

class 		Menu
{
public:
	Menu(void);
	~Menu(void);

private:
	sf::Sprite		_sprite;
};

};
#endif /* !GGJ_MENU_H_ */