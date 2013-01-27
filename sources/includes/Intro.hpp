#ifndef				INTRO_H_
# define			INTRO_H_

class Intro
{
public:
	Intro();
	~Intro();

	void			update();
	bool			isTerminated() const;

private:
	bool			_isTerminated;
	/* data */
};

#endif /* !INTRO_H_ */