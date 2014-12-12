#ifndef ANALOG_MENU_H_
#define ANALOG_MENU_H_

#define MIN_ANALOG_CHANNEL 0
// The last channel is always used for batt voltage so we do not have 
// access to it (hence our max channel is 6 not 7)
#define MAX_ANALOG_CHANNEL 6 

#include "base.h"

class AnalogMenu : public BaseMenu
{
	
public:
	         AnalogMenu ();
	virtual ~AnalogMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
	
	int             currentChannelNum_m;
	AnalogChannel * channel_mp[MAX_ANALOG_CHANNEL + 1];
};

#endif // ANALOG_MENU_H_
