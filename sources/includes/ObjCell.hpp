#ifndef				OBJCELL_H_
# define			OBJCELL_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				ObjCell : public GGJ::Object
{
public:
	ObjCell(b2Body* body);
	~ObjCell(void);

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

#endif /* OBJCELL_H_ */