#include "SimulateToolBar.h"

SimulateToolBar::SimulateToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

//Required parameters to start execution
void SimulateToolBar::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	//Prints action message
	pOut->PrintMsg("View simulation toolbar");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}

//Action execution
void SimulateToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateSimulationToolBar();
	
}

void SimulateToolBar::Undo() {
	return;
}

void SimulateToolBar::Redo() {
	return;
}

SimulateToolBar::~SimulateToolBar() {

}