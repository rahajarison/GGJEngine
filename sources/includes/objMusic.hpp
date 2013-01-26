#ifndef				OBJ_MUSIC
# define			OBJ_MUSIC

#include			<GGJObject.hpp>

class		ObjMusic : public GGJ::Object
{
public:
	ObjMusic(void);
	virtual ~ObjMusic(void);

	virtual void	update(void);	
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);
};

#endif /* !OBJ_MUSIC */