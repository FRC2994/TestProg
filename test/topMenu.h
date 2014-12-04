#ifndef TOPMENU_MENU_H_
#define TOPMENU_MENU_H_

#include "base.h"

class TopMenu : public BaseMenu
{
public:
	TopMenu ();
	
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
private:
	menuType HandleSelect ();
};

#endif // TOPMENU_MENU_H_
