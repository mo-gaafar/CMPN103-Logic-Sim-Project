#include "GateToolBar.h"

//Constructor
GateToolBar::GateToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

//Required parameters for action execution
void GateToolBar::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Prints action message
	pOut->PrintMsg("View add gate toolbar");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}

//Action to be executed
void GateToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateGateToolBar();

}

void GateToolBar::Undo() {
	return;
}

void GateToolBar::Redo() {
	return;
}

GateToolBar::~GateToolBar() {

}