#include "Copy.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include "..\Components\Component.h"
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

void Copy::Execute() {
		ReadActionParameters();
		Output* pOut = pManager->GetOutput(); //gets pointer from appmanager
		Component** CompList = pManager->GetCompList(); //Gets pointer to main array of components
		for (int i = 0; i < pManager->GetCompCount(); i++)
		{
			if (CompList[i] != NULL)
				if (CompList[i]->GetSelectedComponent() == true)
				{
					pManager->SetCopied(CompList[i]);
					pOut->PrintMsg("Copied Successfully");
				}
			/*Input* pIn = pManager->GetInput();
			Output* pOut = pManager->GetOutput();
			ReadActionParameters();

			pManager->SetCopied(Copied);
			pOut->PrintMsg("Copied Successfully");*/
		}
		pManager->AddComponent(pManager->GetCopied);
	}


void Copy::Undo()
{}
void Copy::Redo()
{}