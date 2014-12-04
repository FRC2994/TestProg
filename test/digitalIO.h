#ifndef DIGITALIO_MENU_H_
#define DIGITALIO_MENU_H_

#include "base.h"

// To get around the fact that we do not have a common base class through which
// we can have a single pointer to point to either an input or an output we have
// one for each direction as follows:
// 	Direction DigitalInput DigitalOutput
//	  Input     NonNULL        Null
//	  Output     NULL         NonNULL

typedef struct {
	DigitalInput  * DigitalInput_p;
	DigitalOutput * DigitalOutput_p;
} DigitalIOEntry;

class DigitalIO
{
public:
	DigitalIO ();
	~DigitalIO ();
	
	bool IsInput (int channel);
	void SetToInput (int channel, bool input);
	bool GetValue (int channel);
	void SetValue (int channel, bool value);
	
	DigitalSource * GetInputPointer (int channel);

	static DigitalIO * GetInstance ();
	
private:
	static DigitalIO * instance_m;
	
	DigitalIOEntry DIOTable_mp[NUM_DIO_CHANNELS];
};

#endif // DIGITALIO_MENU_H_
