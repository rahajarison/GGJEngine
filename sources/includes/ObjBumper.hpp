#ifndef				OBJBUMPER_H_
# define			OBJBUMPER_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				ObjBumper : public GGJ::Object
{
public:
	ObjBumper(b2Body* body);
	~ObjBumper(void);

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

#endif /* OBJBUMPER_H_ */