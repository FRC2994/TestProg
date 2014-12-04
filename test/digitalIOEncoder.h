#ifndef DIGITALIOENCODER_MENU_H_
#define DIGITALIOENCODER_MENU_H_

#include "base.h"	// Not necessary
#include "digitalIO.h"

class DigitalIOEncoderMenu : public BaseMenu
{
public:
	         DigitalIOEncoderMenu ();
	virtual ~DigitalIOEncoderMenu();
	
	void     doIndexUp ();
	void     doIndexDown ();
	menuType HandleSelectLeft ();
	menuType HandleSelectRight ();
	void     UpdateDisplay ();
	
	void CreateAndStartEncoder();
	void StopAndDestroyEncoder();

	int currentChannelNumA_m;
	int currentChannelNumB_m;
	
	Encoder *   encoder_mp;
	DigitalIO * digitalIO_mp;
};

#endif // DIGITALIOENCODER_MENU_H_
