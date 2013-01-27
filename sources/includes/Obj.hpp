#ifndef				OBJ_H_
# define			OBJ_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				Obj : public GGJ::Object
{
public:
	Obj(const std::string & fileName, b2Body* body);
	~Obj(void);

	// Callbacks
	virtual void	update(void);
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);

private:
	sf::Sprite		_skin;
	b2Body*			_body;
};

#endif /* OBJ_H_ */