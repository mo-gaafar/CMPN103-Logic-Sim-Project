#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Light Emitting Diode : Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the LED gate



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
		LED* pA = new LED(GInfo, LED_FANOUT);
		pManager->AddComponent(pA);
		pOut->ClearStatusBar();

	}
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}

