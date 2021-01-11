#include "Connection.h"

Connection::Connection(GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}

void Connection::setDestPinIndex(int Index)
{
	DstPinIndex = Index;
}
int Connection::getDestPinIndex()
{
	return DstPinIndex;
}
void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus(SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, Selected);


	GraphicsInfo GInfo = GetCompInfo();
	GraphicsInfo LInfo;
	LInfo.x1 = ((GInfo.x2 + GInfo.x1) / 2);
	LInfo.y1 = ((GInfo.y1 + GInfo.y2) / 2) - 20;
	pOut->DrawString(LInfo, m_Label);
}

Component* Connection::GetSrcComponent()
{
	return SrcPin->getComponent();
}

Component* Connection::GetDstComponent()
{
	return DstPin->getComponent();
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}

/*void Connection::SetEndPoints(int &x2, int&y2);
{
	GfxInfo
}*/

int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::Save(ofstream& print)
{
	//Needs a source/dst comp id getter
	//Consider making a nondefault constructor that takes dst and source pin and deduces gfxinfo instead?

	print << "\t" <<GetSrcComponent()->GetID() << "\t" << GetDstComponent()->GetID() << "\t" << this->getDestPinIndex() <<endl;
}

//PLACEHOLDER FOR NOW
InputPin* Connection::GetInputpinCoordinates(int& X_in, int& Y_in, int& Index) {
	setDestPinIndex(Index);
	return NULL;
}
OutputPin* Connection::GetOutputpinCoordinates(int& X_in, int& Y_in) {
	return NULL;
}
Component* Connection::MakeCopy(Component* c)
{
	/*GraphicsInfo temp;
	temp.x1 = (c->GetGraphicsInfo())->x1;
	temp.x2 = (c->GetGraphicsInfo())->x2;
	temp.y1 = (c->GetGraphicsInfo())->y1;
	temp.y2 = (c->GetGraphicsInfo())->y2;
	Switch* ptr = new Switch(temp, SWITCH_FANOUT);
	ptr->setLabel(c->GetLabel());
	return ptr; */
	return c;
}