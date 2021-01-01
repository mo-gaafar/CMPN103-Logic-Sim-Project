#include "AddBuff.h"
#include "..\ApplicationManager.h"

AddBuff::AddBuff(ApplicationManager* pApp) :Action(pApp)
{
}

AddBuff::~AddBuff(void)
{
}

void AddBuff::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBuff::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the Buff gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Buff* pA = new Buff(GInfo, Buff_FANOUT);
	pManager->AddComponent(pA);

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Enter component label: ");
	GraphicsInfo LInfo;
	LInfo.x1 = GInfo.x1;
	LInfo.y1 = GInfo.y1 - 20;
	string tempst = pIn->GetSrting(pOut);
	pOut->DrawString(LInfo, tempst);
	pOut->ClearStatusBar();
}

void AddBuff::Undo()
{}

void AddBuff::Redo()
{}

