#ifndef			OBJ_DEBUG_H_
# define		OBJ_DEBUG_H_

# include		<GGJObject.hpp>
# include		<SFML/Graphics.hpp>

class			ObjDebug : public GGJ::Object
{
public:
	//ObjDebug(b2body*) // TODO changer le constructeur
	ObjDebug(void);
	virtual ~ObjDebug(void);

	void			applyToSprite(void);
	virtual void	update(void);	
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);	

private:
	sf::Shape		_sprite;
};

#endif