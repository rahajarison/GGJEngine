#ifndef			GGJ_CALLBACK_H_
# define		GGJ_CALLBACK_H_

namespace GGJ
{
typedef void	(*callback)(void* params);

struct registeringCallback
{
	registeringCallback(void);
	registeringCallback(callback func, void* parameters);
	callback 	function;
	void*		params;
};

};

#endif	/* !GGJ_CALLBACK_H_ */