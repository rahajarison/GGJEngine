#include		<iostream>
#include		<GGJContext.hpp>
#include		<GGJResourcesLoader.hpp>
#include		"engine/Define.h"

namespace GGJ
{
Context* Context::_instance = 0;
const unsigned int Context::NB_POOL_OBJECTS = 20;
Context::Context(void) : _map(0), _isRunning(false), _isPaused(false), _isInGame(false)
{
	_map = new Map();
	if (GGJ::ResourcesLoader::loadImage("contours_noirs.png"))
	{
		sf::Image* iContours_noirs = GGJ::ResourcesLoader::getImage("contours_noirs.png");
		if (iContours_noirs)
		{
			sf::Sprite*		sprite = new sf::Sprite(*iContours_noirs);

			sprite->SetScale(0.79f, 0.79f);
			_hudElements.push_back(sprite);
		}
	}
}
Context::~Context(void)
{
}

void		Context::gameCycle(void)
{
	update();
	if (_isRunning)
	{
		_window.clear();
		dispatchEvents();
		drawBackground();
		drawObjects();
		drawHUD();
		_window.display();
	}
}
void		Context::menuCycle(void)
{
	sf::Event 	event;

	_window.clear();
	_window.accessRenderWindow().SetView(_window.
		accessRenderWindow().GetDefaultView());
	while (_window.accessRenderWindow().GetEvent(event))
	{
		if (event.Type == sf::Event::Closed)
		{
        	stop();
        	return;
        }
        else if (event.Type == sf::Event::KeyPressed &&
        		event.Key.Code == sf::Key::Return)
        	_isInGame = true;
    }
    _menu.draw(_window.accessRenderWindow());
	_window.display();
}

void		Context::run(void)
{
	_isRunning = true;
	while (_isRunning)
	{
		if (_isInGame)
			gameCycle();
		else
			menuCycle();
	}
}
void		Context::stop(void)
{
	// TODO implement
	// quitter la Map et les objets, vider la ram, les callbacks
	_window.close();
	_isRunning = false;
}
void		Context::setPause(bool status)	{	_isPaused = status;		}

void		Context::update(void)
{
	std::vector<registeringCallback>::iterator it = _callbacksUpdate.begin();
	std::vector<registeringCallback>::iterator end = _callbacksUpdate.end();
	std::vector<Object*> objects = _map->getObjects();
	std::vector<Object*>::const_iterator itObj = objects.begin();
	std::vector<Object*>::const_iterator endObj = objects.end();

	while (it != end)
	{
		(*(it->function))(it->params);
		++it;
	}
	while (itObj != endObj)
	{
		(*itObj)->update();
		++itObj;
	}
}
void		Context::dispatchEvents(void)
{
	sf::Event 	event;

	while (_window.accessRenderWindow().GetEvent(event))
	{
		if (event.Type == sf::Event::Closed)
		{
        	stop();
        	return;
        }
		std::vector<std::pair<sf::Event, registeringCallback> >::iterator it = _callbacksEvent.begin();
		std::vector<std::pair<sf::Event, registeringCallback> >::iterator end = _callbacksEvent.end();

		while (it != end)
		{
			std::pair<sf::Event, registeringCallback> value = *it;
			if (it->first.Type == event.Type &&
				it->first.Key.Code == event.Key.Code)
				(*(it->second.function))(it->second.params);
			++it;
		}
	}
}
void		Context::registerOnEvent(const sf::Event& event,
									registeringCallback function)
{
	_callbacksEvent.push_back(std::pair<sf::Event, registeringCallback>(event, function));
	// _callbacksEvent[event] = function;
}
void		Context::registerCallback(registeringCallback callback)
{
	_callbacksUpdate.push_back(callback);
}
void		Context::drawBackground(void)
{
	_window.accessRenderWindow().SetView(_window.
		accessRenderWindow().GetDefaultView());
	if (_map)
		_map->drawBackground(_window.accessRenderWindow());
}
void		Context::drawObjects(void)
{
	// _view.Zoom(0.99f); // MOTHAFUCKABEST FEATURE
	_window.accessRenderWindow().SetView(_view);
	if (_map)
		_map->drawObjects(_window.accessRenderWindow());		
}
void		Context::drawHUD(void)
{
	std::vector<sf::Sprite*>::iterator it = _hudElements.begin();
	std::vector<sf::Sprite*>::iterator end = _hudElements.end();
	_window.accessRenderWindow().SetView(_window.
		accessRenderWindow().GetDefaultView());

	while (it != end)
	{
		_window.accessRenderWindow().Draw(**it);
		++it;
	}
}

void		Context::setFramerateLimit(unsigned int limit) {	_window.accessRenderWindow().SetFramerateLimit(limit);	}
// void		Context::loadMap(const std::string& filename)
// {
	// if (_map)
		// delete _map;
	// _map = new Map(filename);
// }
void		Context::attachObject(Object& object)
{
	if (_map)
		_map->attachObject(object);
}
void		Context::detachObject(Object& object)
{
	if (_map)
		_map->detachObject(object);
}
Context& Context::getSingleton(void)
{
	if (!Context::_instance)
		Context::_instance = new Context;
	return (*Context::_instance);
}
void	Context::deleteSingleton(void)
{
	delete Context::_instance;
	Context::_instance = 0;
}
Window&	Context::getWindow(void)
{	return (this->_window);	}

float		Context::getFrameTime(void)
{
	return (Context::getSingleton()._window.accessRenderWindow().GetFrameTime());
}
void		Context::registerOnRam(const std::string& key, void* params)
{
	_ram[key] = params;
}
void*		Context::getValueOfRam(const std::string& key)
{
	std::map<std::string, void*>::iterator it = _ram.find(key);
	if (it != _ram.end())
		return (it->second);
	return (0);
}
bool		Context::isPaused(void) const
{
	return (_isPaused);
}
void		Context::addHUDElement(sf::Sprite* sprite)
{
	_hudElements.push_back(sprite);
}
sf::View&	Context::accessView(void)	{	return (_view);		}

void		Context::removeObjectsWithTag(const std::string& tag)
{
	_map->removeObjectsWithTag(tag);
}

};