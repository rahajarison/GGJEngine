#ifndef			GGJ_OBJECT_H_
# define		GGJ_OBJECT_H_

#include		<string>
#include		<map>
#include		<SFML/Graphics.hpp>

namespace GGJ
{
	class		Object
	{
	public:
		virtual ~Object(void);
		
		void			init(const std::string& name);
		// Callbacks
		virtual void	update(void) = 0;
		virtual void	draw(sf::RenderWindow& window) = 0;
		virtual	void	call(Object& otherObject) = 0;

		void			setPosX(double posX);
		void			setPosY(double posY);
		void			setPos(double posX, double posY);
		void			translate(double posX, double posY);
		// void			applyToSprite(void);
		// void			rotate(?);

		double			getPosX(void) const;
		double			getPosY(void) const;
		double			getWidth(void) const;
		double			getHeight(void) const;

		// Mechanics
		void				load(void);
		void				addTag(const std::pair<std::string, std::string>& tag);
		const std::string&	getTag(const std::string& tag) const;
		static bool			ABBAcollide(const Object& a, const Object& b);
		
	protected:
		std::string				_name; // TODO Charger dans un fichier les images et leur positions
		double					_posX;
		double					_posY;
		double					_width;
		double					_height;
		// bool					_mustCollide;
		std::map<std::string, std::string>		_tags;

	public:
		static const std::string	EMPTY_TAG;
		static const std::string	EXTENSION;
	};

};

#endif /* !GGJ_OBJECT_H_ */