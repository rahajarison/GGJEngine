#ifndef				OBJDEADCELL_H_
# define			OBJDEADCELL_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				ObjDeadCell : public GGJ::Object
{
public:
	ObjDeadCell(b2Body* body);
	~ObjDeadCell(void);

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

#endif /* OBJDEADCELL_H_ */