#ifndef BASE_H_
#define BASE_H_

#include "WPILib.h"

// The menus shown on the LCD are organized as follows:
//
//                          +---------------------+   
//                          +         Top         +   
//                          +---------------------+   
//                                |    |    |
//            +-------------------+    |    +--------------------+
//            |                        |                         |
// +---------------------+  +---------------------+   +---------------------+
// +       Analog        +  +       Digital       +   +       Solenoid      +
// +---------------------+  +---------------------+   +---------------------+
//                                |    |    |
//            +-------------------+    |    +--------------------+
//            |                        |                         |
// +---------------------+  +---------------------+   +---------------------+
// +     Digital PWM     +  +     Digital IO      +   +    Digital Relay    +
// +---------------------+  +---------------------+   +---------------------+
//                                |    |    |
//            +-------------------+    |    +--------------------+
//            |                        |                         |
// +---------------------+  +---------------------+   +---------------------+
// +  Digital IO State   +  +  Digital IO Clock   +   + Digital IO Encoder  +
// +---------------------+  +---------------------+   +---------------------+

// The complete list of menus in the test program
typedef enum 
{
	TOP,				// Points to analog, digitalTop, and solenoid
	ANALOG, 			// Handles analog module inputs
	DIGITAL_TOP, 		// Points to digitalPWM, digitalIO, and digitalRelay
	SOLENOID,			// Handles solenoid module outputs
	DIGITAL_PWM, 		// Handles digital module PWM outputs
	DIGITAL_IO,			// Points to digitalIOState, digitalIOClock, and digitalIOEncoder
	DIGITAL_RELAY,		// Handles digital module relay outputs
	DIGITAL_IO_STATE,	// Handles digital IOs as ON or OFF
	DIGITAL_IO_CLOCK,	// Handles digital IOs and clocks
	DIGITAL_IO_ENCODER,	// Handles a pair of digital IOs as an encoder input
	NUM_MENU_TYPE
} menuType;

// For convenience when calling DriverStaionLCF::PrintfLine (and etc.)
#define LCD1 DriverStationLCD::kUser_Line1
#define LCD2 DriverStationLCD::kUser_Line2
#define LCD3 DriverStationLCD::kUser_Line3
#define LCD4 DriverStationLCD::kUser_Line4
#define LCD5 DriverStationLCD::kUser_Line5
#define LCD6 DriverStationLCD::kUser_Line6

// ----------------------------------------------------------------------------
// Base class for all of the other menus in the system
// ----------------------------------------------------------------------------

// The menu base class contains all of the basic operations of a menu
// with up to six lines of 20 characters (the LCD display on the driver
// station. Each menu must handle four buttons for navigation and 
// selection:
//   Index Up - move the menu selection asterisk up one line of the menu
//   Index Down - move the menu selection asterisk down one line of the menu
//   Select Right - select the next (incrementally higher) option or
//                  value for a given menu line
//   Select Left - delect the previous (incrementally lower) option or
//                 value for a given menu line.
// The methods provided by this base class are meant to be overriden by
// menu-specific versions in all derived classes. We are creating the base 
// class to allow us to use a base-class pointer to refer to any derived
// class instance.

class BaseMenu
{

public:
	         BaseMenu();
	virtual ~BaseMenu ();
	
	void     HandleIndexUp ();
	void     HandleIndexDown ();
	
	virtual  menuType HandleSelectLeft ();
	virtual  menuType HandleSelectRight ();
	
	virtual void UpdateDisplay ();
	virtual void SetSpeed (float speed);

	void SetCallingMenu (menuType callingMenu);
	
	DriverStationLCD::Line IndexToLCDLine (int line);
	
	int index_m;
	int maxIndex_m;
	int minIndex_m;
	
	menuType           callingMenu_m;
	DriverStationLCD * dsLCD;
};

// ----------------------------------------------------------------------------
// TOP menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SOLENOID menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// ANALOG menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// A class to handle the digital IO ports for the DIGITAL_* menus
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// DIGITAL_TOP menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// DIGITAL_PWM menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// DIGITAL_IO menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// RELAY menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Digital IO State menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// DIGITAL_IO_ENCODER menu
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// DIGITAL_IO_CLOCK menu
// ----------------------------------------------------------------------------

#define NUM_DIO_CHANNELS 14
#define MIN_DIO_CHANNEL  0

#endif

