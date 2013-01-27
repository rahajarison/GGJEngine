#ifndef				OBJ_BACKGROUND_H_
# define			OBJ_BACKGROUND_H_

#include			<GGJObject.hpp>

class 				ObjBackground : public GGJ::Object
{
public:
	ObjBackground(void);
	~ObjBackground(void);

	// Callbacks
	virtual void	update(void);
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);

private:
	sf::Image*		_image;
	sf::Sprite		_sprite;
	float			_speed;
};

#endif /* !OBJ_BACKGROUND_H_ */