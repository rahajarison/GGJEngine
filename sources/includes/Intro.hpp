#ifndef				INTRO_H_
# define			INTRO_H_

# include			<SFML/Graphics.hpp>

class Intro
{
public:
	Intro();
	~Intro();

	void			update();
	void			draw(sf::RenderWindow& window);
	bool			isTerminated() const;

private:
	sf::Sprite		_text;
	sf::Clock		_clock;
	bool			_isTerminated;

public:
	static const std::string	TEXT_NAME;
};

#endif /* !INTRO_H_ */