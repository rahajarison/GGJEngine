#include	<GGJResourcesLoader.hpp>
#include	"ObjPattern.hpp"

ObjPattern::ObjPattern(const std::string& filename, float x2, float y2) : x(x2), y(y2) 
{
	if (GGJ::ResourcesLoader::loadImage(filename))
	{
		sf::Image* image = GGJ::ResourcesLoader::getImage(filename);
		this->skin.SetImage(*image);
		this->skin.SetPosition(this->x, this->y);
	}
}

ObjPattern::~ObjPattern(void)
{
}

void	ObjPattern::update(void)
{
	// this->skin.SetPosition(this->x, this->y)
}
void	ObjPattern::draw(sf::RenderWindow& window)
{
	window.Draw(this->skin);
}
void	ObjPattern::call(Object&)
{

}