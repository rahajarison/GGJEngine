#ifndef				GGJ_MAP_H_
# define			GGJ_MAP_H_

#include			<string>
#include			<vector>
#include			<SFML/Audio.hpp>
#include			<SFML/Graphics.hpp>
#include			<GGJObject.hpp>

namespace GGJ
{
class		Map
{
public:
	// Map(const std::string& filename);
	Map(void);
	~Map(void); // desallocate every objects

	const std::vector<Object*>& getObjects(void) const;

	void		attachObject(Object& object);
	void		detachObject(Object& object);

	void		drawObjects(sf::RenderWindow& window);
private:
	// std::string	_file;
	double		_beginPosX;
	double		_beginPosY;
	double		_endAPosX;
	double		_endBPosX;
	double		_endAPosY;
	double		_endBPosY;

	std::vector<sf::Sprite*>		_sprites;
	std::vector<Object*>		_objects;
	sf::Music					_music;

public:
	static const std::string	EXTENSION;
};
};

#endif /* !GGJ_MAP_H_ */