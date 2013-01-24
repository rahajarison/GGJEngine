#ifndef			GGJCONTEXT_H_
# define		GGJCONTEXT_H_

namespace GGJ
{
	class		Context
	{
	public:
		static Context&	getSingleton(void);
		static void		deleteSingleton(void);
	
		Window&			getWindow(void);
		void			run(void);

		// void			attachObject(Object& object);
		// void			detachObject(Object& object);
	private:
		Context(void);

		static Context*	_instance;
		Window			_window;
		// bool			_isPaused;
		// bool			_isInGame;
		bool			_isRunning;

	public:
		static const unsigned int 	NB_POOL_OBJECTS;
	};
};

#endif /* !GGJCONTEXT_H_ */