#include "ExitProgram.h"
#include "..\ApplicationManager.h"

ExitProgram::ExitProgram(ApplicationManager* pApp) :Action(pApp)
{
}

ExitProgram::~ExitProgram(void)
{
}

void ExitProgram::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Double click to exit program");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


void ExitProgram::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	pOut->ClearStatusBar();
	//Maybe add save warning 

}

void ExitProgram::Undo()
{}

void ExitProgram::Redo()
{}

