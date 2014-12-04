#ifndef DIGITALIOMENU_MENU_H_
#define DIGITALIOMENU_MENU_H_

#include "base.h"

class DigitalIOMenu : public BaseMenu
{
	
public:
	DigitalIOMenu ();
	
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
};

#endif // DIGITALIOMENU_MENU_H_
