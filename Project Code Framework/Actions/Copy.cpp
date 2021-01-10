#include "Copy.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include<iostream>
using namespace std;
Copy::Copy(ApplicationManager* pManager) :Action(pManager)
{
	Copied = NULL;
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
	//pOut->ClearStatusBar();
	

}

void Copy::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	pManager->SetCopied(Copied);
	pOut->PrintMsg("Copied Successfully");

}

void Copy::Undo()
{}
void Copy::Redo()
{}