#include "Simulate.h"
#include "..\ApplicationManager.h"

Simulate::Simulate(ApplicationManager* pApp) :Action(pApp)
{
}

Simulate::~Simulate(void)
{
}

void Simulate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Simulating Circuit");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}


void Simulate::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->ReSortCompList();
	Component** CompList = pManager->GetCompList();
	
	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		for (int i = 0; i < pManager->GetCompCount(); i++)
		{
			CompList[i]->Operate();
		}
		
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	//Print Action Message
	pOut->PrintMsg("Done simulating.");
	
	
}

void Simulate::Undo()
{}

void Simulate::Redo()
{}

