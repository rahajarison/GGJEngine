#include			<iostream>
#include			<GGJResourcesLoader.hpp>
#include			"AudioManager.hpp"

AudioManager::AudioManager(std::list<std::string> & musicNames, std::list<std::string> & soundNames, const char * mainTheme) : _mainTheme(mainTheme)
{
	std::list<std::string>::iterator it = musicNames.begin();
	std::list<std::string>::iterator itEnd = musicNames.end();
	std::list<std::string>::iterator it2 = soundNames.begin();
	std::list<std::string>::iterator itEnd2 = soundNames.end();

	for (; it != itEnd; ++it)
	{
		GGJ::ResourcesLoader::loadMusic(*it);
	}
	for (; it2 != itEnd2; ++it2)
	{
		GGJ::ResourcesLoader::loadSoundBuffer(*it2);
	}

	if (GGJ::ResourcesLoader::loadMusic(mainTheme))
	{
		sf::Music* music = GGJ::ResourcesLoader::getMusic(mainTheme);
		music->Play();
		music->SetLoop(true);
	}
}
AudioManager::~AudioManager(void)
{
}

void			AudioManager::playSound(const char * soundName)
{
	sf::SoundBuffer* buffer = GGJ::ResourcesLoader::getSoundBuffer(soundName);
	sf::Sound		sound;

	sound.SetBuffer(*buffer);
	sound.Play();
}
void			AudioManager::stop(void)
{ 
	GGJ::ResourcesLoader::getMusic(_mainTheme)->Stop();
}