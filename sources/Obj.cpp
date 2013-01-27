#include	<GGJResourcesLoader.hpp>
#include	"Obj.hpp"

Obj::Obj(const std::string & fileName, b2Body* body) : _body(body)
{
	sf::Image* image;

		if (GGJ::ResourcesLoader::loadImage(fileName))
	{
		image = GGJ::ResourcesLoader::getImage(fileName);
		_skin.SetImage(*image);
		_skin.SetCenter(image->GetWidth() / 2, image->GetHeight() / 2);
		update();
	}

}
Obj::~Obj(void)
{
}

void Obj::update(void)
{
	const b2Vec2& vector = _body->GetPosition();
	_skin.SetPosition(vector.x, vector.y);
}

void Obj::draw(sf::RenderWindow& window)
{
	window.Draw(_skin);
}

void Obj::call(Object&)
{
}