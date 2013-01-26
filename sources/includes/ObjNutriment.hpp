#ifndef			OBJNUTRIMENT_H_
# define		OBJNUTRIMENT_H_

#include		<Box2D/Box2D.h>
#include		<GGJObject.hpp>


class 				ObjNutriment : public GGJ::Object
{
public:
	ObjNutriment(b2Body* body);
	~ObjNutriment(void);

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

#endif	/* OBJNUTRIMENT_H_ */