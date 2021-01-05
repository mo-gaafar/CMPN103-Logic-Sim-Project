#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x1 = GetInputPinStatus(1);
	int x2 = GetInputPinStatus(2);
	if (x1 != x2)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, Selected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

InputPin* XNOR2::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index)
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