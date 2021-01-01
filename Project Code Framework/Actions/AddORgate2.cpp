#include "..\actions\AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the OR2 gate



	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;

	//Checks if click is not within drawing area
	if (Cy < UI.ToolBarHeight && Cx < UI.ToolItemWidth * ITM_DSN_CNT)
	{
		pOut->PrintMsg("Error, you have to draw within the drawing area");
	}
	else {
		OR2* pA = new OR2(GInfo, OR2_FANOUT);
		pManager->AddComponent(pA);


		pOut->PrintMsg("Enter component label: ");
		GraphicsInfo LInfo;
		LInfo.x1 = GInfo.x1;
		LInfo.y1 = GInfo.y1 - 20;
		//string tempst = "Label";
		//pOut->DrawString(LInfo, tempst);

		string tempst = pIn->GetSrting(pOut);
		pOut->DrawString(LInfo, tempst);
		pOut->ClearStatusBar();

	}
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}

