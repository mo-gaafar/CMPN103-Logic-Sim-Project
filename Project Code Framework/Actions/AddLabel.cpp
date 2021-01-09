#include "AddLabel.h"
#include "..\ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{

}


void AddLabel::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Enter component label: ");

	//ReadActionParameters();

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo;
	GInfo.x1 = Cx - Len / 2;
	GInfo.y1 = Cy - Wdth / 2;


	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;

	string tempst = pIn->GetSrting(pOut);
	pOut->DrawString(LInfo, tempst);
	//Missing SetLabel?
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

