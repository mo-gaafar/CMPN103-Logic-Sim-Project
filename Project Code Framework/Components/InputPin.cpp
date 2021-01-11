#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

//returns pointer to gate component
Component* InputPin::getComponent()
{
	return pComp;
}
void InputPin::setIndex(int rIndex)
{
	Index = rIndex;
}
int InputPin::getIndex()
{
	return Index;
}

//InputPin::~InputPin()
//{
//}