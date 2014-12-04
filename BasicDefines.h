#ifndef BASICDEFINES_H_
#define BASICDEFINES_H_

// Types
typedef enum
{
	kEventErr, kEventNone, kEventOpened, kEventClosed
} EventType;
	
typedef enum
{
	kStateOpen, kStateClosed, kStateErr
} StateType;

typedef struct
{
	StateType state; 
	EventType event;
	bool enabled;
} ButtonEntry;

#define LEFT_DRIVE_PWM 0
#define RIGHT_DRIVE_PWM 1

#endif
