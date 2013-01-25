#ifndef			GGJ_RESOURCE_LOADER
# define		GGJ_RESOURCE_LOADER

# include		<map>
# include		<SFML/Audio.hpp>
# include		<SFML/Graphics.hpp>

namespace GGJ
{
class ResourcesLoader
{
public:
	static ResourcesLoader*	getSingleton(void);

	static bool				loadMusic(const std::string& filename);
	static bool				loadSoundBuffer(const std::string& filename);
	static bool				loadImage(const std::string& filename);

	static sf::Music*		getMusic(const std::string& filename);
	static sf::SoundBuffer*	getSoundBuffer(const std::string& filename);
	static sf::Image*		getImage(const std::string& filename);

private:
	ResourcesLoader(void);
	~ResourcesLoader(void);

	static ResourcesLoader*				_singleton;
	std::map<std::string, sf::Music*>	_musics;
	std::map<std::string, sf::SoundBuffer*>	_soundBuffer;
	std::map<std::string, sf::Image*>	_images;
};

};

#endif /* !GGJ_RESOURCE_LOADER */