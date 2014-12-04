#ifndef RELAY_MENU_H_
#define RELAY_MENU_H_

#define MIN_RELAY_CHANNEL 0
#define MAX_RELAY_CHANNEL 7

#include "base.h"

class RelayMenu : public BaseMenu
{
	
public:
	         RelayMenu ();
	virtual ~RelayMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
	
	void IncrementChannelValue ();
	void DecrementChannelValue ();
	int  RelayValueToInt (Relay::Value value);

	
	int          currentChannelNum_m;
	Relay::Value currentChannelValue_m;
	Relay *      channel_mp[MAX_RELAY_CHANNEL + 1];
};

#endif // RELAY_MENU_H_
