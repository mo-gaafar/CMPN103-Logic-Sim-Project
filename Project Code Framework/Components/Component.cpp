#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;

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

