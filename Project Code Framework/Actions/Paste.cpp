#include "Paste.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include "..\Components\Component.h"
#include<iostream>

Paste::Paste(ApplicationManager* pManager) :Action(pManager)
{
	Copied = NULL;
}

Paste::~Paste()
{
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Paste copied component");
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	pManager->AddComponent(pManager->GetCopied());
	pOut->PrintMsg("Pasted successfully");
}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
