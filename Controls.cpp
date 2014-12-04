#include "Controls.h"

Controls::Controls()
{
	this->controlsInstance = new Controls();

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

	delete this->controlsInstance;
}

void Controls::SetSpeed(int channel, float speed)
{
	if (speed != 0.0)
	{
		if (activeChannels[channel] == false)
		{
			activeChannels[channel] = true;
			channel_mp[channel]->Set(speed);
		}
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
