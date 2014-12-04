#ifndef DIGITALIOSTATE_MENU_H_
#define DIGITALIOSTATE_MENU_H_

#include "base.h"	// Not necessary
#include "digitalIO.h"

class DigitalIOStateMenu : public BaseMenu
{	
public:
	         DigitalIOStateMenu ();
	virtual ~DigitalIOStateMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
	
	int  currentChannelNum_m;
	bool currentChannelValue_m;
	
	DigitalIO * digitalIO_mp;
};

#endif // DIGITALIOSTATE_MENU_H_
