#ifndef				AUDIOMANAGER_H_
# define			AUDIOMANAGER_H_

# include			<list>
# include			<string>

class		AudioManager
{
public:
	AudioManager(std::list<std::string> & musicNames, std::list<std::string> & soundNames, const char * mainTheme);
	~AudioManager(void);

	void 	playSound(const char * soundName);
	void 	stop(void);

private:
	const char * _mainTheme;
};

#endif /* !AUDIOMANAGER_H_ */