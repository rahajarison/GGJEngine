#include		<GGJContext.hpp>

namespace GGJ
{
Context* Context::_instance = 0;
const unsigned int Context::NB_POOL_OBJECTS = 20;
Context::Context(void) : _isRunning(false)
{	
}
Context& Context::getSingleton(void)
{
	if (!Context::_instance)
		Context::_instance = new Context;
	return (Context::_instance);
}
void	Context::deleteSingleton(void)
{
	delete Context::_instance;
	Context::_instance = 0;
}
Window&	Context::getWindow(void)
{	return (this->_window);	}

void		Context::run(void)
{
	// TODO : implement game cycle
	if (!_isRunning)
	{
		
	}
}

};