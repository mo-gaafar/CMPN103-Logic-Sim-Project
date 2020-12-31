#include "SimulateToolBar.h"

/* Constructor */
SimulateToolBar::SimulateToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void SimulateToolBar::ReadActionParameters()
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
void SimulateToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateSimulationToolBar();
	
}

/* Undo action */
void SimulateToolBar::Undo() {
	return;
}

/* Redo action */
void SimulateToolBar::Redo() {
	return;
}

/* Destructor */
SimulateToolBar::~SimulateToolBar() {

}