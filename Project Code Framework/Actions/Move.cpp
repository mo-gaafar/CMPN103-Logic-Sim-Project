#include "Move.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
#include "..\Components\Component.h"
#include<iostream>

Move::Move(ApplicationManager* pManager) :Action(pManager)
{
}

Move::~Move()
{
}

void Move::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Move selected component");
}

void Move::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput(); //gets pointer from appmanager
	Component** CompList = pManager->GetCompList(); //Gets pointer to main array of components
	Input* pIn = pManager->GetInput();
	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (CompList[i] != NULL)
			if (CompList[i]->GetSelectedComponent() == true)
			{
				pIn->GetPointClicked(Cx, Cy);
				GraphicsInfo GInfo;
				GInfo.x1 = Cx - UI.AND2_Height / 2;
				GInfo.x2 = Cx + UI.AND2_Height / 2;
				GInfo.y1 = Cy - UI.AND2_Height / 2;
				GInfo.y2 = Cy + UI.AND2_Height / 2;
				CompList[i]->SetCompInfo(GInfo);
				pOut->PrintMsg("Move successfully");
			}
	}
}

void Move::Undo()
{
}

void Move::Redo()
{
}
