#ifndef		OBJPATTERN_H_
# define	OBJPATTERN_H_

#include	<string>
#include	<GGJObject.hpp>

class ObjPattern : public GGJ::Object
{
public:
	ObjPattern(const std::string& filename, float x, float y);
	~ObjPattern(void);

	virtual void	update(void);
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);

private:
	sf::Sprite		skin;
	float			x;
	float			y;
};

#endif /* OBJPATTERN_H_ */