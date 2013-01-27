#ifndef				FADE_ANIM_H_
# define			FADE_ANIM_H_

#include			<SFML/Graphics.hpp>
#include			<GGJAnimation.hpp>

class FadeAnim : public GGJ::Animation
{
public:
	FadeAnim();
	virtual ~FadeAnim();

	virtual void		callbackUpdate(float sinceLastFrame);
	virtual void		draw(sf::RenderWindow& window);

private:
	sf::Sprite			_sprite;
	bool				_stepOne;
};
#endif /* !FADE_ANIM */