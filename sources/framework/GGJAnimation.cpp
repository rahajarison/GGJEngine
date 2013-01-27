#include			<GGJAnimation.hpp>
#include			<GGJContext.hpp>

namespace GGJ
{

Animation::Animation(float length) : _length(length), _cursor(length), _launched(false)
{
	Animation::_animations.push_back(this);
}

void		Animation::update(float sinceLastFrame)
{
	_cursor -= sinceLastFrame;
	if (_cursor > 0)
		callbackUpdate(sinceLastFrame);
	else
		onTerminate();
}
void		Animation::callbackUpdate(float sinceLastFrame)
{
	// sf::RenderWindow& window = GGJ::Context::getSingleton().accessRenderWindow();


}
void		Animation::onTerminate(void)
{
	_cursor = _length;
	_launched = false;
}
void		Animation::launch(void)
{
	_launched = true;
}

void		Animation::draw(sf::RenderWindow& window)
{
}
void		Animation::isTerminated(void)	{	return (_launched);	}

};