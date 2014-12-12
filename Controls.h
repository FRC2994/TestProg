#ifndef CONTROLS_H_
#define CONTROLS_H_

#define MIN_PWM_CHANNEL 0
#define MAX_PWM_CHANNEL 9

#include "WPILib.h"

class Controls
{
public:
	virtual ~Controls();
	
	static Controls * GetInstance();
	
	void SetSpeed(int channel, float speed);
	float GetSpeed(int channel);
	
	Jaguar * channel_mp[MAX_PWM_CHANNEL + 1];
	bool activeChannels[MAX_PWM_CHANNEL + 1];
	
protected:
	Controls();
	
private:
	static Controls * instance;
};

#endif // CONTROLS_H_
