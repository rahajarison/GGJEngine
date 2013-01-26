#ifndef			OBJ_DEBUG_H_
# define		OBJ_DEBUG_H_

# include		<GGJObject.hpp>
# include		<SFML/Graphics.hpp>
# include		"engine/Character.h"

class			ObjDebug : public GGJ::Object
{
public:
	ObjDebug(b2Body* body);
	ObjDebug(void);
	virtual ~ObjDebug(void);

	void			applyToSprite(void);
	virtual void	update(void);	
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);	

private:
	sf::Shape		_sprite;
	b2Body*			_body;
};

#endif