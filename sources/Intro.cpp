#include		<GGJResourcesLoader.hpp>
#include		<GGJContext.hpp>
#include		"Intro.hpp"
#include		"FadeAnim.hpp"

const std::string Intro::TEXT_NAME = "texte_1.png";

Intro::Intro() :
_isTerminated(false)
{
	if (GGJ::ResourcesLoader::loadImage(TEXT_NAME))
	{
		sf::Image* image = GGJ::ResourcesLoader::getImage(TEXT_NAME);
		_text.SetImage(*image);
	}
}
Intro::~Intro()
{
}

void			Intro::update(void)
{
	float time = _clock.GetElapsedTime();

	if (time >= 10)
	{
		FadeAnim* fade = new FadeAnim();
		fade->draw(GGJ::Context::getSingleton().getWindow().accessRenderWindow());
		_isTerminated = true;
	}
	else
	{
		draw(GGJ::Context::getSingleton().getWindow().accessRenderWindow());
	}
}
void			Intro::draw(sf::RenderWindow& window)
{
	window.Draw(_text);
}
bool			Intro::isTerminated(void) const
{
	return (_isTerminated);
}