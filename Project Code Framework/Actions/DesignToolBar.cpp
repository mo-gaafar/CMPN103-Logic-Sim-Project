#include "DesignToolBar.h"

DesignToolBar::DesignToolBar(ApplicationManager* pAppMan) : Action(pAppMan) {

}

//Required parameters to start execution
void DesignToolBar::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Prints action message
	pOut->PrintMsg("View design toolbar");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}

//Action execution
void DesignToolBar::Execute() {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDesignToolBar();

}

void DesignToolBar::Undo() {
	return;
}

void DesignToolBar::Redo() {
	return;
}

DesignToolBar::~DesignToolBar() {

}