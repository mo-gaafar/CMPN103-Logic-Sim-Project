#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

//returns pointer to connection component
Component* InputPin::getComponent()
{
	return pComp;
}

//InputPin::~InputPin()
//{
//}