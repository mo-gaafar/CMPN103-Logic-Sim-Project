#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	Changed = LOW;
}


void LED::Operate()
{
	if (GetInputPinStatus(1) == HIGH)
		Changed = HIGH;
	else
		Changed = LOW;
	//return;
}


// Function Draw
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo, Selected, Changed);


	GraphicsInfo GInfo = GetCompInfo();
	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;
	pOut->DrawString(LInfo, m_Label);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


InputPin* LED::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index)
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

void LED::Save(ofstream& print)
{
	print << "LED\t" << ID << "\t" << GetLabel() << "\t" << GetCompInfo().x1
		<< "\t" << GetCompInfo().x2 << "\t" << GetCompInfo().y1 << "\t" << GetCompInfo().y2 << endl;
}

Component* LED::MakeCopy(Component* c)
{
	GraphicsInfo temp;
	temp.x1 = (c->GetGraphicsInfo())->x1;
	temp.x2 = (c->GetGraphicsInfo())->x2;
	temp.y1 = (c->GetGraphicsInfo())->y1;
	temp.y2 = (c->GetGraphicsInfo())->y2;
	LED* ptr = new LED(temp, LED_FANOUT);
	//ptr->setLabel(c->GetLabel());
	return ptr;
}