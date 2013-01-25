#include		<GGJContext.hpp>

namespace GGJ
{
Context* Context::_instance = 0;
const unsigned int Context::NB_POOL_OBJECTS = 20;
Context::Context(void) : _map(0), _isRunning(false), _isPaused(false)
{	
}
Context::~Context(void)
{
}

void		Context::run(void)
{
	// TODO : implement game cycle
	// dispatch events
	// callable
	while (_isRunning)
	{
		update();
		dispatchEvents();
		_window.clear();
		drawObjects();
		drawHUD();
		_window.display();	
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

	while (it != end)
	{
		(*(it->function))(it->params);
		++it;
	}
}
void		Context::dispatchEvents(void)
{
	sf::Event 	event;

	while (_window.accessRenderWindow().GetEvent(event))
	{
		std::vector<std::pair<sf::Event, registeringCallback> >::iterator it = _callbacksEvent.begin();
		std::vector<std::pair<sf::Event, registeringCallback> >::iterator end = _callbacksEvent.end();

		while (it != end)
		{
			// what about copying all the datas ? ;)
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
void		Context::drawObjects(void)
{
	_window.accessRenderWindow().SetView(_view);
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
void		Context::loadMap(const std::string& filename)
{
	if (_map)
		delete _map;
	_map = new Map(filename);
}
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

};