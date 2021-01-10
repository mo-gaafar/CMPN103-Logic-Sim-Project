#include "Cut.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include "..\Components\Component.h"
#include<iostream>

Cut::Cut(ApplicationManager* pManager) :Action(pManager)
{
	Copied = NULL;
}

Cut::~Cut()
{
}

void Cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Cut selected component");
}

void Cut::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput(); //gets pointer from appmanager
	Component** CompList = pManager->GetCompList(); //Gets pointer to main array of components
	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (CompList[i] != NULL)
			if (CompList[i]->GetSelectedComponent() == true)
			{
				pManager->SetCopied(CompList[i]);
				pManager->ExecuteAction(DEL);
				pOut->ClearStatusBar();
				pOut->PrintMsg("Cut Successfully");
			}
	}
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
