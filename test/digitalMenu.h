#ifndef DIGITALMENU_MENU_H_
#define DIGITALMENU_MENU_H_

#include "base.h"

class DigitalMenu : public BaseMenu
{
	
public:
	DigitalMenu ();
	
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
};

#endif // DIGITALMENU_MENU_H_
