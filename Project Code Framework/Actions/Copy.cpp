#include "Copy.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include<iostream>
using namespace std;
Copy::Copy(ApplicationManager* pManager) :Action(pManager)
{
	Copied = NULL;
	CancelOperation = false;
}
Copy:: ~Copy()
{
}
void Copy::ReadActionParameters() /// SELECT IS OPERATION CANCELLED 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Copy selected component");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	/*int nSelected = pManager->GetSelectedSize();
	if (nSelected > 1)
	{
		pOut->PrintMsg("Operation Cancelled: You can only copy one component");
		CancelOperation = true;
		return;
	}
	else if (nSelected == 0)
	{
		pOut->PrintMsg("Operation Cancelled: There are no selected components");
		CancelOperation = true;
		return;
	}
	*/

}

void Copy::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (CancelOperation) return;

	pManager->SetCopied(Copied);
	pOut->PrintMsg("Copied Successfully");

}

void Copy::Undo()
{}
void Copy::Redo()
{}