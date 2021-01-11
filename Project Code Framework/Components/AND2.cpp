#include "AND2.h"

AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	//ID = COUNT;
	//COUNT++;
}



void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x1 = GetInputPinStatus(1);
	int x2 = GetInputPinStatus(2);
	if (x1 == 1 && x2 == 1)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo,Selected);


	GraphicsInfo GInfo = GetCompInfo();
	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;
	pOut->DrawString(LInfo, m_Label);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

InputPin* AND2::GetInputpinCoordinates(int & X_in ,int & Y_in, int &Index)
{
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in < (m_GfxInfo.y1 + UI.AND2_Height / 2)))
	{
		X_in = m_GfxInfo.x1;
		Y_in = m_GfxInfo.y1+UI.AND2_Height/3;
		Index = 0;
		return &this->m_InputPins[Index];
	}
	if ((X_in < m_GfxInfo.x1 + 2 * UI.AND2_Height / 10) && (X_in > m_GfxInfo.x1) && (Y_in > (m_GfxInfo.y1 + UI.AND2_Height / 2)))
	{
		X_in = m_GfxInfo.x1;
		Y_in = m_GfxInfo.y1 + UI.AND2_Height * 2 / 3;
		Index = 1; 
		return &this->m_InputPins[Index];

	}
	return NULL;
}
Component* AND2::MakeCopy(Component* c)
{
	GraphicsInfo temp;
	temp.x1 = (c->GetGraphicsInfo())->x1+20;
	temp.x2 = (c->GetGraphicsInfo())->x2+20;
	temp.y1 = (c->GetGraphicsInfo())->y1+20;
	temp.y2 = (c->GetGraphicsInfo())->y2+20;
	AND2* ptr = new AND2(temp, AND2_FANOUT);
	//ptr->setLabel(c->GetLabel());
	return ptr;
}

void AND2::Save(ofstream& print)
{
	print << "AND2\t" << ID << "\t" << GetLabel() << "\t" << GetCompInfo().x1
	<< "\t"<< GetCompInfo().x2 << "\t"<<GetCompInfo().y1 << "\t"<<GetCompInfo().y2 << endl;
}

