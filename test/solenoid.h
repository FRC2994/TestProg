#ifndef SOLENOID_MENU_H_
#define SOLENOID_MENU_H_

#define MIN_SOLENOID_CHANNEL 0
#define MAX_SOLENOID_CHANNEL 7

#include "base.h"

typedef enum {
	SINGLE,
	DUAL
} modeType;

class SolenoidMenu : public BaseMenu
{
	
public:
	         SolenoidMenu ();
	virtual ~SolenoidMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     SwitchMode();
	void     UpdateDisplay ();
	
	int        mode_m;
	int        currentChannelNumA_m;
	int        currentChannelNumB_m;
	Solenoid * channel_mp[MAX_SOLENOID_CHANNEL + 1];
	DoubleSolenoid * doubleSolenoid_mp;
};

#endif
