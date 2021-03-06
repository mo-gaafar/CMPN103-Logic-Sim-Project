#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	COPY,
	CUT,
	PASTE,

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT_AREA,
	SELECT_BUTTON,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	GATE_MODE,

	EXIT,		//Exit the application

	PROBE,
	VALIDATE,
	SIMULATE,

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	SIM_TOOL,	//A click on an empty place in the sim tool bar
	GATE_TOOL //A click on an empty place in the sim tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	GATE
};

enum GateMenuItem
{
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,		//NAND2 gate item in menu
	ITM_NOR2,		//NOR2 gate item in menu
	ITM_XOR2,		//XOR2 gate item in menu
	ITM_XNOR2,		//XNOR2 gate item in menu
	ITM_Buff,		//BUFFER gate item in menu
	ITM_INV,		//NOT gate item in menu
	ITM_AND3,		//AND3 gate item in menu
	ITM_NOR3,		//NOR3 gate item in menu
	ITM_XOR3,		//XOR3 gate item in menu
	ITM_SWITCH,		//SWITCH item in menu
	ITM_LED,		//LED item in menu
	ITM_DSN_MODE_GATE,
	ITM_EXIT_GATE,		//Exit item

	ITM_GATE_CNT //items in gate menu
};
enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_UNDO,
	ITM_REDO,
	ITM_CUT,
	ITM_COPY,
	ITM_PASTE,
	ITM_MOVE,
	ITM_EDITLABEL,
	ITM_ADDLABEL,
	ITM_ADDCONNECTION,
	ITM_ADDGATE,
	ITM_DEL,
	ITM_LOAD,
	ITM_SAVE,
	ITM_SIM_MODE_DSN, //Simulation mode button in design menu

	ITM_EXIT_DSN,		//Exit item
	
	//ITM_SELECT,

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,	//Simulate menu item
	ITM_VALID, //Validation button
	ITM_TRUTH, //Truth table
	ITM_CHANGESWITCH, //Toggles selected Switch
	ITM_PROBE,//Probe button
	ITM_DSN_MODE_SIM,//Back to design mode

	BLANK1,
	BLANK2,
	BLANK3,
	BLANK4,
	BLANK5,
	BLANK6,
	BLANK7,
	BLANK8,


	ITM_EXIT_SIM,
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5,	//Default fan out of 2-input AND gate
	AND3_FANOUT = 5,
	NOR3_FANOUT = 5,
	XOR3_FANOUT = 5,
	OR2_FANOUT = 5,
	NAND2_FANOUT = 5,
	NOR2_FANOUT = 5,
	XOR2_FANOUT = 5,
	XNOR2_FANOUT = 5,
	Buff_FANOUT = 5,
	INV_FANOUT = 5,
	LED_FANOUT = 0,
	Switch_FANOUT = 5,
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif