#ifndef			GGJCONTEXT_H_
# define		GGJCONTEXT_H_

#include		<vector>
#include		<map>
#include		<GGJWindow.hpp>
#include		<GGJCallback.hpp>
#include		<GGJObject.hpp>
#include		<GGJMap.hpp>
#include		<GGJMenu.hpp>
#include		"engine/World.h"
#include		"Intro.hpp"

namespace GGJ
{
	class		Context
	{
	public:
		static Context&	getSingleton(void);
		static void		deleteSingleton(void);
	
		void			setFramerateLimit(unsigned int limit);
		// void			loadMap(const std::string& filename);
		Window&			getWindow(void);

		void			run(void);
		void			stop(void);
		void			setPause(bool status);

		void			attachObject(Object& object);
		void			detachObject(Object& object);
		bool			isPaused(void) const; // To easyly implement pause
		void			dispatchEvents(void);
		void			registerOnEvent(const sf::Event& event,
									registeringCallback callback);
		void			registerCallback(registeringCallback callback);
		static float	getFrameTime(void);
		void			registerOnRam(const std::string& key, void* value);
		void*			getValueOfRam(const std::string& key);

		void			addHUDElement(sf::Sprite* sprite);
		sf::View&		accessView(void);
	
		void			removeObjectsWithTag(const std::string& tag);

		World							_world;

	private:
		Context(void);
		~Context(void);
		void			drawBackground(void);
		void			drawObjects(void);
		void			drawHUD(void);
		void			update(void);
		void			gameCycle(void);
		void			menuCycle(void);
		void			introCycle(void);

		static Context*					_instance;
		Window							_window;
		Map*							_map;
		bool							_isPaused;
		bool							_isInGame;
		bool							_isInIntro;
		bool							_isRunning;
		std::map<std::string, void*>	_ram;
		std::vector<std::pair<sf::Event, registeringCallback> > _callbacksEvent;
		// std::map<sf::Event, registeringCallback>	_callbacksEvent;
		std::vector<registeringCallback>			_callbacksUpdate;
		sf::View						_view;
		std::vector<sf::Sprite*>		_hudElements;
		Menu							_menu;
		Intro							_intro;

	public:
		static const unsigned int 	NB_POOL_OBJECTS;
	};
};

#endif /* !GGJCONTEXT_H_ */