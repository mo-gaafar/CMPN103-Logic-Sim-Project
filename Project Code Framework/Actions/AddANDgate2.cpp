#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}


void AddANDgate2::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate


	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;

	//Checks if click is not within drawing area
	if (Cy < UI.ToolBarHeight && Cx < UI.ToolItemWidth * ITM_DSN_CNT)
	{
		pOut->PrintMsg("Error, you have to draw within the drawing area");
	}
	else {
		AND2* pA = new AND2(GInfo, AND2_FANOUT);
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

void AddANDgate2::Undo()
{}

void AddANDgate2::Redo()
{}

