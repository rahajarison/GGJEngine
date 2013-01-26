#include	<iostream>
#include	<GGJMap.hpp>
#include	<algorithm>
#include	<GGJResourcesLoader.hpp>

namespace GGJ
{
// Map::Map(const std::string& filename) : _file(filename)
// {
//  // load
// }
Map::Map(void)
{
	if (GGJ::ResourcesLoader::loadImage("background_rose.png"))
	{
		{
			sf::Image*	iBackground_rose = GGJ::ResourcesLoader::getImage("background_rose.png");
			if (iBackground_rose)
				_sprites.push_back(new sf::Sprite(*iBackground_rose));
		}
	
		// {
		// 	sf::Image*	iPattern1= GGJ::ResourcesLoader::getImage("background_rose.png");
		// 	if (iPattern1)
		// 	{
		// 		sf::Sprite*	pattern1 = new sf::Sprite(*iPattern1);
		// 		pattern1->SetPosition(0, 0);
		// 		_sprites.push_back(pattern1);
		// 	}
		// 	else
		// 		std::cerr << "Va tfaire floute" << std::endl;
		// }

	
		// {
		// 	sf::Image*	iBackground_rose = GGJ::ResourcesLoader::getImage("pattern2.png");
		// 	if (iBackground_rose)
		// 	{
		// 		sf::Sprite*	sprite = new sf::Sprite(*iBackground_rose);
		// 		sprite->SetPosition(0, 1024);
		// 		_sprites.push_back(sprite);
		// 	}
		// }
	
		// std::cout << "Allo" << std::endl;
		// {
		// 	sf::Image*	iBackground_rose = GGJ::ResourcesLoader::getImage("background_rose.png");
		// 	if (iBackground_rose)
		// 		_sprites.push_back(new sf::Sprite(*iBackground_rose));
		// }
	

	}
	else
		std::cerr << "Impossible d'afficher le background" << std::endl;
}
Map::~Map(void)
{
	std::vector<Object*>::iterator it = _objects.begin();
	while (it != _objects.end())
	{
		delete *it;
		it = _objects.erase(it);
	}
}
const std::vector<Object*>& Map::getObjects(void) const
{
	return (_objects);
}
void		Map::attachObject(Object& object)
{
	_objects.push_back(&object);
}
void		Map::detachObject(Object& object)
{
	std::vector<Object*>::iterator it = std::find(_objects.begin(),
		_objects.end(), &object);
	if (it != _objects.end())
		_objects.erase(it);
}
void		Map::drawBackground(sf::RenderWindow& window)
{	
	std::vector<sf::Sprite*>::iterator it = _sprites.begin();
	std::vector<sf::Sprite*>::iterator end = _sprites.end();
	unsigned int i = 0;

	while (it != end)
	{
		std::cout << " Tu es content de toi  " << i << std::endl;
		window.Draw(**it);
		++i;
		++it;
	}
}
void		Map::drawObjects(sf::RenderWindow& window)
{
	std::vector<Object*>::iterator it = _objects.begin();
	std::vector<Object*>::iterator end = _objects.end();

	while (it != end)
	{
		(*it)->draw(window);
		++it;
	}
}
void		Map::removeObjectsWithTag(const std::string& tag)
{
	std::vector<Object*>::iterator it = _objects.begin();
	std::vector<Object*>::iterator end = _objects.end();

	while (it != end)
	{
		if ((*it)->getTag(tag) != GGJ::Object::EMPTY_TAG)
		{
			Object*	obj = *it;
			it = _objects.erase(it);
			delete obj;
		}
		else
			++it;
	}
}
};