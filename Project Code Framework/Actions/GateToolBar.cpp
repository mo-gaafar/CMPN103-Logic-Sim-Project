#include "GateToolBar.h"

/* Constructor */
GateToolBar::GateToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void GateToolBar::ReadActionParameters()
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
void GateToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateGateToolBar();

}

/* Undo action */
void GateToolBar::Undo() {
	return;
}

/* Redo action */
void GateToolBar::Redo() {
	return;
}

/* Destructor */
GateToolBar::~GateToolBar() {

}