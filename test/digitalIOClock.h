#ifndef DIGITALIOCLOCK_MENU_H_
#define DIGITALIOCLOCK_MENU_H_

#include "base.h"	// Not necessary
#include "digitalIO.h"

class DigitalIOClockMenu : public BaseMenu
{
public:
	         DigitalIOClockMenu ();
	virtual ~DigitalIOClockMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
	
	void CreateAndStartCounter();
	void StopAndDestroyCounter();

	int currentChannelNum_m;
	
	Counter *   counter_mp;
	DigitalIO * digitalIO_mp;
};

#endif // DIGITALIOCLOCK_MENU_H_
