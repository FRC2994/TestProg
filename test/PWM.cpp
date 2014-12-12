#include "PWM.h"

// PWM Menu


PWMMenu::PWMMenu()
{
	// The PWM menu looks like this (not including the 1st 2 columns):
	// 1:PWM
	// 2: Channel A: #
	// 3: Channel B: #
	// 4: Enabled:
	// 5: Back
	// 6:

	index_m = 2;
	maxIndex_m = 5;

	// Start out with channel 0 for each
	currentChannelNumA_m = 0;
	currentChannelNumB_m = 1;
	enabled_m = NEITHER;
	
	controls = Controls::GetInstance();


	// Create a PWM object for every channel on the module
	// (note that PWM channels are numbered 1->10 in the API and 1->10 on the module)
	// We are using 0->9
}

PWMMenu::~PWMMenu()
{
}

menuType PWMMenu::HandleSelectLeft()
{
	switch (index_m)
	{
	case 2: // Decrement channel A number 
		currentChannelNumA_m--;
		// Make sure channels A and B are never the same
		if (currentChannelNumA_m == currentChannelNumB_m)
		{
			currentChannelNumA_m--;
		}
		if (currentChannelNumA_m < MIN_PWM_CHANNEL)
		{
			currentChannelNumA_m = MAX_PWM_CHANNEL;
			// Make sure channels A and B are never the same
			if (currentChannelNumA_m == currentChannelNumB_m)
			{
				currentChannelNumA_m--;
			}
		}
		break;
	case 3: // Decrement channel B number
		currentChannelNumB_m--;
		// Make sure channels A and B are never the same
		if (currentChannelNumB_m == currentChannelNumA_m)
		{
			currentChannelNumB_m--;
		}
		if (currentChannelNumB_m < MIN_PWM_CHANNEL)
		{
			currentChannelNumB_m = MAX_PWM_CHANNEL;
			// Make sure channels A and B are never the same
			if (currentChannelNumB_m == currentChannelNumA_m)
			{
				currentChannelNumB_m--;
			}
		}
		break;
	case 4: // Decrement enabled flag
		enabled_m--;
		if (enabled_m < NEITHER)
		{
			enabled_m = BOTH;
		}
		break;
	case 5: // Return to previous menu
		return callingMenu_m;
		break;
	default:
		break;
	}
	return DIGITAL_PWM;
}

menuType PWMMenu::HandleSelectRight()
{
	switch (index_m)
	{
	case 2: // Increment channel A number 
		currentChannelNumA_m++;
		// Make sure channels A and B are never the same
		if (currentChannelNumA_m == currentChannelNumB_m)
		{
			currentChannelNumA_m++;
		}
		if (currentChannelNumA_m > MAX_PWM_CHANNEL)
		{
			currentChannelNumA_m = MIN_PWM_CHANNEL;
			// Make sure channels A and B are never the same
			if (currentChannelNumA_m == currentChannelNumB_m)
			{
				currentChannelNumA_m++;
			}
		}
		break;
	case 3: // Decrement channel value
		currentChannelNumB_m++;
		// Make sure channels A and B are never the same
		if (currentChannelNumB_m == currentChannelNumA_m)
		{
			currentChannelNumB_m++;
		}
		if (currentChannelNumB_m > MAX_PWM_CHANNEL)
		{
			currentChannelNumB_m = MIN_PWM_CHANNEL;
			// Make sure channels A and B are never the same
			if (currentChannelNumB_m == currentChannelNumA_m)
			{
				currentChannelNumB_m++;
			}
		}
		break;
	case 4: // Increment the enabled flag
		enabled_m++;
		if (enabled_m > BOTH)
		{
			enabled_m = NEITHER;
		}
	default:
		break;
	}
	return DIGITAL_PWM;
}

void PWMMenu::SetSpeed(float speed)
{
	// To keep motor safety tmeouts from occuring we need to set all of the motor
	// controllers each pass of the main program loop (and this method is called 
	// in each pass of the main program loop)

	if (BOTH == enabled_m) // Reverse order cuz of glitchy stuff to make sure you dont goof up
	{
		controls->SetSpeed(currentChannelNumA_m, speed);
		controls->SetSpeed(currentChannelNumB_m, speed);
	}
	else if (A_ONLY == enabled_m)
	{
		controls->SetSpeed(currentChannelNumA_m, speed);
	}
	else if (B_ONLY == enabled_m)
	{
		controls->SetSpeed(currentChannelNumB_m, speed);
	}
}

void PWMMenu::UpdateDisplay()
{
	const char * enabledStrings[] =
	{
		"Neither",
		"A Only",
		"B Only",
		"Both"
	};
	int chanA = currentChannelNumA_m + 1;
	int chanB = currentChannelNumB_m + 1;

	dsLCD->Clear();
	dsLCD->PrintfLine(LCD1, "PWM");
	dsLCD->PrintfLine(LCD2, " Channel A: %d %5.2f", chanA, controls->GetSpeed(currentChannelNumA_m));
	dsLCD->PrintfLine(LCD3, " Channel B: %d %5.2f", chanB, controls->GetSpeed(currentChannelNumB_m));
	dsLCD->PrintfLine(LCD4, " Enabled: %s", enabledStrings[enabled_m]);
	dsLCD->PrintfLine(LCD5, " Back");
	dsLCD->Printf(IndexToLCDLine(index_m), 1, "*");

	dsLCD->UpdateLCD();
}
