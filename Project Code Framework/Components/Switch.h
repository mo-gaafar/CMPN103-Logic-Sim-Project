#pragma once
#include "Gate.h"
class Switch :public Gate
{
public:
	Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output
	virtual void Draw(Output* pOut);	//Draws  gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	InputPin* GetInputpinCoordinates(int& X_in, int& Y_in, int& Index);
	virtual void Save(ofstream& print);
	virtual Component* MakeCopy(Component*);

};

