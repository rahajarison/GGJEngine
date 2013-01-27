#include		<iostream>
#include		<GGJResourcesLoader.hpp>
#include		<GGJContext.hpp>
#include		"BoomBoomAnim.hpp"

BoomBoomAnim::BoomBoomAnim(void) : Animation(2)
{
	for (unsigned int i = 0; i < 4; ++i)
		beated[i] = false;
}
BoomBoomAnim::~BoomBoomAnim(void)
{
	std::cout << "stop" << std::endl;
}

void		BoomBoomAnim::draw(sf::RenderWindow& window)
{
	// window.SetView(window.GetDefaultView());
	// window.Draw(_sprite);
	// window.SetView(GGJ::Context::getSingleton().accessView());
}
void		BoomBoomAnim::callbackUpdate(float sinceLastFrame)
{
	GGJ::Context&	context = GGJ::Context::getSingleton();

	if (_cursor > 1.75f && !beated[3])
	{
		context.accessView().Zoom(0.83334f);
		beated[3] = true;
	}
	else if (_cursor > 1.55f && !beated[2])
	{
		context.accessView().Zoom(1.2f);
		beated[2] = true;
	}
	// else 
	// if (_cursor > 0.35f && !beated[1])
	// {
	// 	context.accessView().Zoom(0.9090f);
	// 	beated[1] = true;
	// }
	// else if (_cursor > 0.25f && !beated[0])
	// {
	// 	context.accessView().Zoom(1.1f);
	// 	beated[0] = true;
	// }

	// context.accessView().Zoom(1.030);
	// if (_stepOne)
	// {
	// 	_sprite.SetColor(sf::Color(255, 255, 255, 255 - (_cursor * 255 / _length)));
	// 	if (_cursor >= _length / 2)
	// 		_stepOne = false;
	// }
	// else
		// _sprite.SetColor(sf::Color(255, 255, 255, _cursor * 255 / _length));
}