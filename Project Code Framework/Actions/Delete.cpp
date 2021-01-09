#include "Delete.h"
#include "../Components/Component.h"

Delete::Delete(ApplicationManager* pAppMan) : Action(pAppMan) {

}

//Required parameters to start execution
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Prints action message
	pOut->PrintMsg("Delete Selected Component");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}

//Action execution
void Delete::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput(); //gets pointer from appmanager
	Component** CompList = pManager->GetCompList(); //Gets pointer to main array of components

	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (CompList[i]!=NULL)
		if (CompList[i]->GetSelectedComponent() == true)
		{
			CompList[i]->SelectComponent(false);
			CompList[i]->~Component();

			CompList[i]= NULL;//Connections part still to be implemented
		}
		
	}
	pOut->PrintMsg("Delete Action Executed");
	pManager->ReSortCompList(); //Fixes the list of components
}

void Delete::Undo() {
	return;
}

void Delete::Redo() {
	return;
}

Delete::~Delete() {

}