#include "INV.h"
INV::INV(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	if (GetInputPinStatus(1) == LOW){
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(m_GfxInfo, Selected);
}

//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
  
InputPin* INV::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index)
{
	int HeightCenter = UI.AND2_Height / 2;

	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && Y_in< (m_GfxInfo.y2 - HeightCenter + 18) && Y_in >(m_GfxInfo.y2 - HeightCenter - 18))
	{
		X_in = m_GfxInfo.x1;
		Y_in = m_GfxInfo.y1 + UI.AND2_Height / 2;
		Index = 0;
		return &this->m_InputPins[Index];
	}
	return NULL;
}