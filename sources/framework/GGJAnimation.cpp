#include			<GGJAnimation.hpp>
#include			<GGJContext.hpp>

namespace GGJ
{

std::vector<Animation*> Animation::_animations;

Animation::Animation(float length) : _length(length), _cursor(length), _launched(false)
{
	// Animation::_animations.push_back(this);
}

Animation::~Animation(void)
{
	Animation::removeFromList(this);
}
void		Animation::update(float sinceLastFrame)
{
	_cursor -= sinceLastFrame;
	if (_cursor > 0)
	{
		callbackUpdate(sinceLastFrame);
		draw(GGJ::Context::getSingleton().getWindow().accessRenderWindow());
	}
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

	std::vector<Animation*>::iterator it = _animations.begin();
	std::vector<Animation*>::iterator end = _animations.end();

	while (it != end)
	{
		if (*it == this)
		{
			it = _animations.erase(it);
			end = _animations.end();
		}
		else
			++it;
	}
}
void		Animation::launch(void)
{
	if (_launched == false)
	{
		_launched = true;
		_animations.push_back(this);
	}
}

bool		Animation::isTerminated(void) const	{	return (_launched);	}
void		Animation::updateAll(float sinceLastFrame)
{
	std::vector<Animation*>::iterator it = _animations.begin();
	std::vector<Animation*>::iterator end = _animations.end();

	while (it != end)
	{
		(*it)->update(sinceLastFrame);
		++it;
	}
}
void		Animation::removeFromList(Animation* anim)
{
	std::vector<Animation*>::iterator it = _animations.begin();
	std::vector<Animation*>::iterator end = _animations.end();

	while (it != end)
	{
		if (*it == anim)
			it = _animations.erase(it);
		else
			++it;
	}
}
};