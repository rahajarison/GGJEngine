#ifndef				CELL_H_
# define			CELL_H_

#include	<Box2D/Box2D.h>
#include	<GGJObject.hpp>


class 				Cell : public GGJ::Object
{
public:
	Cell(b2Body* body);
	// Cell(const std::string& filename);
	~Cell(void);

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

#endif /* CELL_H_ */