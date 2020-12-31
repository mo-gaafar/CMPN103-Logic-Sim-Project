#include "DesignToolBar.h"

/* Constructor */
DesignToolBar::DesignToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

/* Reads parameters required for action to execute */
void DesignToolBar::ReadActionParameters()
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
void DesignToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDesignToolBar();

}

/* Undo action */
void DesignToolBar::Undo() {
	return;
}

/* Redo action */
void DesignToolBar::Redo() {
	return;
}

/* Destructor */
DesignToolBar::~DesignToolBar() {

}