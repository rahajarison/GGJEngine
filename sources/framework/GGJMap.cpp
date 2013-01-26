#include	<GGJMap.hpp>
#include	<algorithm>

namespace GGJ
{
// Map::Map(const std::string& filename) : _file(filename)
// {
//  // load
// }
Map::Map(void)
{
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
};