#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	Selected = false;
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
void Component::setID(int i)
{
	ID = i;
}

//////////////////////////////////////////////////////////////////
Component::Component()
{
	Selected = false;
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
{}
int Component::COUNT = 0;
