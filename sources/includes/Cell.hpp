#ifndef				CELL_H_
# define			CELL_H_

#include	<GGJObject.hpp>


class 				Cell : public GGJ::Object
{
public:
	Cell(const std::string& filename);
	~Cell(void);

	// Callbacks
	virtual void	update(void);
	virtual void	draw(sf::RenderWindow& window);
	virtual	void	call(Object& otherObject);

private:
	sf::Sprite		skin;
};

#endif /* CELL_H_ */