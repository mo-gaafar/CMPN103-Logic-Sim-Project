#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x1 = GetInputPinStatus(1);
	int x2 = GetInputPinStatus(2);
	int x3 = GetInputPinStatus(3);

	if (x1 == 0 && x2 == 0 && x3 == 0)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, Selected);



	GraphicsInfo GInfo = GetCompInfo();
	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;
	pOut->DrawString(LInfo, m_Label);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

InputPin* NOR3::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index)
{
	int Pin1, Pin2, Pin3; //Y Locations of pins
	Pin1 = m_GfxInfo.y1 + UI.AND2_Height / 3;

	Pin2 = m_GfxInfo.y1 + UI.AND2_Height / 2;

	Pin3 = m_GfxInfo.y1 + UI.AND2_Height * 2 / 3;

	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in < Pin1 + UI.AND2_Height / 10) && (Y_in > Y_in < Pin1 - UI.AND2_Height / 10))
	{
		X_in = m_GfxInfo.x1;
		Y_in = Pin1;
		Index = 0;
		return &this->m_InputPins[Index];
	}
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in < Pin2 + UI.AND2_Height / 10) && (Y_in > Y_in < Pin2 - UI.AND2_Height / 10))
	{
		X_in = m_GfxInfo.x1;
		Y_in = Pin2;
		Index = 1;
		return &this->m_InputPins[Index];

	}
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in < Pin3 + UI.AND2_Height / 10) && (Y_in > Y_in < Pin3 - UI.AND2_Height / 10))
	{
		X_in = m_GfxInfo.x1;
		Y_in = Pin3;
		Index = 2;
		return &this->m_InputPins[Index];

	}
	return NULL;
}
Component* NOR3::MakeCopy(Component* c)
{
	GraphicsInfo temp;
	temp.x1 = (c->GetGraphicsInfo())->x1;
	temp.x2 = (c->GetGraphicsInfo())->x2;
	temp.y1 = (c->GetGraphicsInfo())->y1;
	temp.y2 = (c->GetGraphicsInfo())->y2;
	NOR3* ptr = new NOR3(temp, NOR3_FANOUT);
	//ptr->setLabel(c->GetLabel());
	return ptr;
}