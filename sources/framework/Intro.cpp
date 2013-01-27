#include		"Intro.hpp"

Intro::Intro() :
_isTerminated(false)
{
}
Intro::~Intro()
{
}
void			Intro::update(void)
{
	// Ton script

	// Pour dire que tu es a la fin de l intro,
	// fais que isTerminated me renvoie true
}
bool			Intro::isTerminated(void) const
{
	return (_isTerminated);
}