#ifndef			GGJLOG_H_
# define		GGJLOG_H_
#include		<string>
#include		<fstream>

namespace GGJ
{
	static char endl = '\n';
	class Log
	{
	public:
		Log(const std::string& filename = "GameLog.txt", bool toOpenNow = true);
		~Log(void);

		bool		open(const std::string& filename);
		void		close(void);
	private:
		std::ofstream	_output;
		bool			_alreadyOpen;

	public:
		template <typename T>
		Log& operator<<(const T& data)
		{		_output << data;	}
	};
};

#endif /* !GGJLOG_H_ */