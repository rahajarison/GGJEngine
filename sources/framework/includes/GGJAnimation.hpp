#ifndef				GGJ_ANIMATION_H_
# define			GGJ_ANIMATION_H_

#include			<vector>
#include			<SFML/Graphics.hpp>

namespace GGJ
{
class 				Animation
{
public:
	Animation(float length);
	virtual ~Animation(void);

	void			update(float sinceLastFrame);
	void			launch(void);
	bool			isTerminated(void) const;
	virtual void	callbackUpdate(float sinceLastFrame);
	void			onTerminate(void);

	static void		updateAll(float sinceLastFrame);
	static void		removeFromList(Animation* anim);

	virtual void	draw(sf::RenderWindow& window) = 0;

protected:
	static std::vector<Animation*>	_animations;

	float							_length;
	float							_cursor;
	bool							_launched;
};

};
#endif /* !GGJ_ANIMATION_H_ */
