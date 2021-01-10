#include "Switch.h"
Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Switch::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x1 = GetInputPinStatus(1);
	if (x1 == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
	//Add you code here
	//Add you code here
}


// Function Draw
// Draws Switch
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo, Selected);



	GraphicsInfo GInfo = GetCompInfo();
	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;
	pOut->DrawString(LInfo, m_Label);
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();;
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	return;
}

//PLACEHOLDER FOR NOW
InputPin* Switch::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index) {
	return NULL;
}
Component* Switch::MakeCopy(Component* c)
{
	GraphicsInfo temp;
	temp.x1 = (c->GetGraphicsInfo())->x1;
	temp.x2 = (c->GetGraphicsInfo())->x2;
	temp.y1 = (c->GetGraphicsInfo())->y1;
	temp.y2 = (c->GetGraphicsInfo())->y2;
	Switch* ptr = new Switch(temp, Switch_FANOUT);
	//ptr->setLabel(c->GetLabel());
	return ptr;
}