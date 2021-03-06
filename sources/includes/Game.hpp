#ifndef				GAME_H_
# define			GAME_H_

void				reloadCells(GGJ::Context* context);
void				Box2DCallback(void*);
void				OnDivideEvent(void* params);
void				OnImpulseEvent(void* params);
void				OnFusionEvent(void* params);

void				OnRightEvent(void* params);
void				OnLeftEvent(void* params);
void				OnFrontEvent(void* params);
void				OnBackEvent(void* params);

void				cameraCallback(void* params);
void				mainCallback(void*);


#endif /* !GAME_H_ */