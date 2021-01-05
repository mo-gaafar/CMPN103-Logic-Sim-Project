#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x1 = GetInputPinStatus(1);
	int x2 = GetInputPinStatus(2);
	int x3 = GetInputPinStatus(3);

	if (x1 == 1 && x2 == 1 && x3 == 1)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo,Selected);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

InputPin* AND3::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index)
{
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in < (m_GfxInfo.y1 + UI.AND2_Height / 2)))
	{
		X_in = m_GfxInfo.x1;
		Y_in = m_GfxInfo.y1 + UI.AND2_Height / 4;
		Index = 0;
		return &this->m_InputPins[Index];
	}
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in > (m_GfxInfo.y1 + UI.AND2_Height / 2)))
	{
		X_in = m_GfxInfo.x1;
		Y_in = m_GfxInfo.y1 + UI.AND2_Height * 3 / 4;
		Index = 1;
		return &this->m_InputPins[Index];

	}
	return NULL;
}