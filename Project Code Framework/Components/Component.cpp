#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	Selected = false;
	ID = rand()% 99999; //Generates Random integer from 0 to 99999
}

void Component::SetLabel(const string& label)
{
	if (label != "") {
		m_Label = label;
	}
}

string Component::GetLabel() const
{
	return m_Label;
}
void Component::SetID(int i)
{
	ID = i;
}
int Component::GetID()
{
	return ID;
}

//////////////////////////////////////////////////////////////////
Component::Component()
{
	Selected = false;
	ID = rand() % 99999; //Generates Random integer from 0 to 99999
}
//////////////////////////////////////////////////////////////////
GraphicsInfo Component::GetCompInfo()
{
	return m_GfxInfo;
}
//////////////////////////////////////////////////////////////////
void Component::SelectComponent(bool s)
{
	Selected = s;
}
//////////////////////////////////////////////////////////////////
bool Component::GetSelectedComponent()
{
	return Selected;
}
//////////////////////////////////////////////////////////////////
Component::~Component()
{
}
//int Component::COUNT = 0;//?????
