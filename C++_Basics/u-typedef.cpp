/********************************************
**		Definiton of user's types          **
*********************************************/

typedef void(*menu_fcn) (void); // definiton of type
menu_fcn command[3]; // using new type

typedef enum {
	Back = 8, Tab = 9, Esc = 27, Enter = 13,
	Down = 0x0150, Left = 0x014b, Right = 0x014d,
	Up = 0x0148, NUL = 0x0103, Shift_Tab = 0x010f
} key_t;

key_t _char; // variable of enum


