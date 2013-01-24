#include		<GGJLog.hpp>

namespace GGJ
{

	Log::Log(const std::string& filename, bool toOpenNow)
	{
		if (toOpenNow)
			open(filename);
	}

	Log::~Log(void)
	{
		close();
	}

	bool			Log::open(const std::string& filename)
	{
		_output.open(filename.c_str());
		if (_output.good())
		{
			_alreadyOpen = true;
			return (true);
		}
		close();
		return (false);
	}
	void			Log::close(void)
	{
		_alreadyOpen = false;
		_output.close();
	}
};