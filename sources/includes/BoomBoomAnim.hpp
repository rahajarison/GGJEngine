#ifndef				BOOM_BOOM_ANIM
# define			BOOM_BOOM_ANIM

#include			<SFML/Graphics.hpp>
#include			<GGJAnimation.hpp>

class BoomBoomAnim : public GGJ::Animation
{
public:
	BoomBoomAnim();
	virtual ~BoomBoomAnim();

	virtual void		callbackUpdate(float sinceLastFrame);
	virtual void		draw(sf::RenderWindow& window);

private:
	sf::Sprite			_sprite;
	float				_second_beat;
	bool				beated[4];
};

#endif /* !BOOM_BOOM_ANIM */