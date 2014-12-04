#ifndef PWM_MENU_H_
#define PWM_MENU_H_

#include "base.h"
#include "../Controls.h"

class PWMMenu : public BaseMenu
{
	typedef enum {
		NEITHER,
		A_ONLY,
		B_ONLY,
		BOTH
	} enabledType;

public:
	PWMMenu();
	virtual ~PWMMenu();

	void     doIndexUp();
	void     doIndexDown();
	menuType HandleSelectLeft();
	menuType HandleSelectRight();
	void     UpdateDisplay();

	void SetSpeed(float speed);

	int currentChannelNumA_m;
	int currentChannelNumB_m;
	int enabled_m;
};

#endif
