#include "Gate.h"
#include "Connection.h"
//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	if (r_Inputs > 0) {
		//Allocate number of input pins (equals r_Inputs)
		m_InputPins = new InputPin[r_Inputs];
		m_Inputs = r_Inputs;	//set no. of inputs of that gate

		//Associate all input pins to this gate
		for (int i = 0; i < m_Inputs; i++)
			m_InputPins[i].setComponent(this);
		//Associates output pin to this gate
		m_OutputPin.setComponent(this);
	}
}
OutputPin* Gate:: GetOutputpinCoordinates(int& X_Out, int& Y_Out)
{
	
		int HeightCenter = UI.AND2_Height / 2;
		if (X_Out<(m_GfxInfo.x2 + 18) && X_Out >(m_GfxInfo.x2 - 18) && Y_Out< (m_GfxInfo.y2 - HeightCenter + 18) && Y_Out >(m_GfxInfo.y2 - HeightCenter - 18))
		{
			//Return Connection location and pointer to outputpin array of objects
			Y_Out = m_GfxInfo.y2-HeightCenter; 
			X_Out = m_GfxInfo.x2;
			return &this->m_OutputPin; //address of output pin object of this gate
		}
		return NULL;

}

