#ifndef				OBJTURNSTILE_H_
# define			OBJTURNSTILE_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				ObjTurnstile : public GGJ::Object
{
public:
	ObjTurnstile(b2Body* body);
	~ObjTurnstile(void);

	// Callbacks
	virtual void	update(void);
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);

private:
	sf::Sprite		skin;
	sf::Sprite		light;
	b2Body*			_body;

public:
	static const std::string	IMAGE_NAME;
	static const std::string	IMAGE2_NAME;
};

#endif /* OBJTURNSTILE_H_ */