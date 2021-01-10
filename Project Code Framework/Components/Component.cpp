#include "Component.h"

Component::Component(GraphicsInfo& r_GfxInfo)
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
GraphicsInfo* Component::GetGraphicsInfo()
{
	return &m_GfxInfo;
}
//////////////////////////////////////////////////////////////////
void Component::SelectComponent(bool s)
{
	Selected = s;
}
//////////////////////////////////////////////////////////////////
bool Component::GetSelectedComponent() //Checks if selected or not
{
	return Selected;
}
void Component::SetCompInfo(GraphicsInfo g)
{
	m_GfxInfo = g;
}
//////////////////////////////////////////////////////////////////
Component::~Component()
{
	
}

