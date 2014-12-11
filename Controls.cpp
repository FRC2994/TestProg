#include "Controls.h"

Controls * Controls::instance = NULL;

Controls::Controls()
{
	for (int i = MIN_PWM_CHANNEL; i <= MAX_PWM_CHANNEL; i++)
	{
		channel_mp[i] = new Jaguar(i + 1);
		channel_mp[i]->SetExpiration(0.2);
		activeChannels[i] = false;
	}
}

Controls::~Controls()
{
	for (int i = MIN_PWM_CHANNEL; i <= MAX_PWM_CHANNEL; i++)
	{
		delete channel_mp[i];
	}
	instance = NULL;
}

Controls * Controls::GetInstance()
{
	if(instance == NULL)
	{
		instance = new Controls();
	}
	return instance;
}

void Controls::SetSpeed(int channel, float speed)
{
	if(activeChannels[channel] == false)
	{
		channel_mp[channel]->Set(speed);
		activeChannels[channel] = true;
	}
	else
	{
		activeChannels[channel] = false;
	}
}

float Controls::GetSpeed(int channel)
{
	return channel_mp[channel]->Get();
}
