#include			<GGJResourcesLoader.hpp>

namespace GGJ
{

bool				ResourcesLoader::loadMusic(const std::string& filename)
{
	sf::Music*		music = new sf::Music();

	if (music->OpenFromFile(filename))
	{
		getSingleton()->_musics[filename] = music;
		return (true);
	}
	return (false);
}
bool				ResourcesLoader::loadSoundBuffer(const std::string& filename)
{
	sf::SoundBuffer*		sound = new sf::SoundBuffer();

	if (sound->LoadFromFile(filename))
	{
		getSingleton()->_soundBuffer[filename] = sound;
		return (true);
	}
	return (false);
}
bool				ResourcesLoader::loadImage(const std::string& filename)
{
	sf::Image*		image = new sf::Image();

	if (image->LoadFromFile(filename))
	{
		getSingleton()->_images[filename] = image;
		return (true);
	}
	return (false);
}

sf::Music*			ResourcesLoader::getMusic(const std::string& filename)
{
	std::map<std::string, sf::Music*>::iterator it = getSingleton()->_musics.find(filename);
	if (it != getSingleton()->_musics.end())
		return (it->second);
	return (0);
}
sf::SoundBuffer*	ResourcesLoader::getSoundBuffer(const std::string& filename)
{
	std::map<std::string, sf::SoundBuffer*>::iterator it = getSingleton()->_soundBuffer.find(filename);
	if (it != getSingleton()->_soundBuffer.end())
		return (it->second);
	return (0);
}
sf::Image*			ResourcesLoader::getImage(const std::string& filename)
{
	std::map<std::string, sf::Image*>::iterator it = getSingleton()->_images.find(filename);
	if (it != getSingleton()->_images.end())
		return (it->second);
	return (0);
}

ResourcesLoader*	ResourcesLoader::_singleton = 0;
ResourcesLoader*	ResourcesLoader::getSingleton(void)
{
	if (!ResourcesLoader::_singleton)
		ResourcesLoader::_singleton = new ResourcesLoader();
	return (ResourcesLoader::_singleton);
}
ResourcesLoader::ResourcesLoader(void)
{
}
ResourcesLoader::~ResourcesLoader(void)
{
}

};