#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate(int r_Inputs, int r_FanOut);
	 OutputPin* GetOutputpinCoordinates(int& X_Out, int& Y_Out); //checks rectangular range of output pin given click coordinates, returns pointer to the selected gate's output pin element
	virtual InputPin* GetInputpinCoordinates(int& X_In, int& Y_In, int& n_Input)=0;//checks rectangular range of input pin, returns x,y of pin and pointer to outputpin object (changes depending on gate location and type)
}; 


#endif
