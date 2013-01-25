#include		<GGJCallback.hpp>

void			defaultCallback(void*)
{
}
GGJ::registeringCallback::registeringCallback(callback func, void* parameters) :
function(func), params(parameters)
{
}
GGJ::registeringCallback::registeringCallback(void) :
function(&defaultCallback), params(0)
{
}