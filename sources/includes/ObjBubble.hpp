#ifndef				OBJBUBBLE_H_
# define			OBJBUBBLE_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				ObjBubble : public GGJ::Object
{
public:
	ObjBubble(b2Body* body);
	~ObjBubble(void);

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

#endif /* OBJBUBBLE_H_ */