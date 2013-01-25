#include		<GGJObject.hpp>
#include		<fstream>

namespace GGJ
{
const std::string	Object::EMPTY_TAG = "";
const std::string	Object::EXTENSION = ".prop";

void		Object::load(void)
{
	// filename loaded after init();
	std::ifstream		file(std::string(_name + Object::EXTENSION).c_str());

	if (file.good())
	{
		// TODO load properties
		// load first lines
		// call ResourcesLoader
	}
	file.close();
}

void					Object::addTag(const std::pair<std::string, std::string>& tag)
{
	_tags[tag.first] = tag.second;
}
const std::string&		Object::getTag(const std::string& tag) const
{
	std::map<std::string, std::string>::const_iterator it = _tags.find(tag);
	if (it != _tags.end())
		return (it->second);
	return (Object::EMPTY_TAG);
}

void		Object::translate(double posX, double posY)
{
	_posX += posX;
	_posY += posY;
}
void		Object::setPos(double posX, double posY)
{
	_posX = posX;
	_posY = posY;
}
bool		Object::ABBAcollide(const Object& a, const Object& b)
{
	if ( (a.getPosX() >= b.getPosX() + b.getWidth()) ||
		 (a.getPosX() + a.getWidth() <= b.getPosX())	||
    	 (a.getPosY() >= b.getPosY() + b.getHeight()) ||
    	 (a.getPosY() + a.getHeight() <= b.getPosY()))
          return false;
   else
          return true; 

    // algortithm:
    //   if((box2.x >= box1.x + box1.w)      // trop à droite
    // || (box2.x + box2.w <= box1.x) // trop à gauche
    // || (box2.y >= box1.y + box1.h) // trop en bas
    // || (box2.y + box2.h <= box1.y))  
}
void		Object::setPosX(double posX) 			{ _posX = posX;	}
void		Object::setPosY(double posY) 			{ _posY = posY;	}
void		Object::init(const std::string& name)	{	this->_name = name; }
double		Object::getPosX(void) const				{ return (_posX);	}
double		Object::getPosY(void) const				{ return (_posY);	}
double		Object::getWidth(void) const			{ return (_width);	}
double		Object::getHeight(void) const			{ return (_height);	}



};