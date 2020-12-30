#include "Select.h"
/* Constructor */
Select::Select(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

/* Executes action */
void Select::Execute() {
	//Get Center point of the Component
	ReadActionParameters();

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	int c;
	Component** CompList = pManager->GetCompList();
	c = pManager->GetCompCount();
	//Output* pOut = pManager->GetOutput();
	//Component* Comp = pManager->GetCompList();

	for (int i = 0; i < c; i++)
	{
		GInfo = CompList[i]->GetCompInfo();
		if ((CompList[i]->GetSelectedComponent() == false) && (Cx >= GInfo.x1 && Cx <= GInfo.x2) && (Cy >= GInfo.y1 && Cy <= GInfo.y2))
		{
			CompList[i]->SelectComponent(true);
			//pOut->PrintMsg(" Label: " + Comp->GetLabel());
		}
		else
			CompList[i]->SelectComponent(false);
	}
	/*if (c == 1)
	{
		GInfo = Comp->GetCompInfo();
		pOut->DrawLabel(GInfo ," Label: " + Comp->GetLabel());
	}*/
}

/* Undo action */
void Select::Undo() {
	return;
}

/* Redo action */
void Select::Redo() {
	return;
}

/* Destructor */
Select::~Select() {

}