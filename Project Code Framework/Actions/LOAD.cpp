#include "Load.h"
#include "../ApplicationManager.h"
#include"Action.h"
#include"../Components/AND2.h"
#include"../Components/AND3.h"
#include"../Components/Buff.h"
#include"../Components/NAND2.h"
#include"../Components/SWITCH.h"
#include"../Components/LED.h"
#include"../Components/INV.h"
#include"../Components/OR2.h"
#include"../Components/XNOR2.h"
#include"../Components/XOR3.h"
#include"../Components/NOR3.h"
#include"../Components/XOR2.h"
#include"../Components/NOR2.h"
#include"../Components/Connection.h"
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;


Load::Load(ApplicationManager* pApp) : Action(pApp)
{
}

Load::~Load()
{
}

void Load::ReadActionParameters()
{
}
void Load::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();

	pOut->PrintMsg("Enter File Name");

	fileName = pIn->GetSrting(pOut);
	int compcountBeforeEmpty = pManager->GetCompCount();

	ifstream read;
	read.open(fileName);
	
	pManager->EmptyComplist();
	if (!read.is_open())
	{
		pOut->PrintMsg("File not found");
		pManager->EmptyComplist();
		pOut->ClearDrawingArea();
	}
	else
	{
		pOut->PrintMsg("File is found");
		string Name, Label;
		int CompCount, ID, xcord, ycord;
		read >> CompCount;
		for (int i = 0; i < CompCount; i++)
		{
			read >> Name >> ID >> Label >> xcord >> ycord;
			CreateComp(Name, ID, Label, xcord, ycord);
		}
		read >> Name;
		/*while (true)
		{
			//cout << "Done for now" << endl;
			int FirstID, SecondID, Pinnumber;
			read >> FirstID >> SecondID >> Pinnumber;
			if (FirstID == -1)
				break;

			//Hassan: ReadConnection needs to be finished
			//ReadConnection(FirstID, SecondID, Pinnumber);
		}*/
		pOut->PrintMsg("Done Loading");
	}
	read.close();
}



void Load::CreateComp(string& Name, int& id, string& label, int& x, int& y)
{
	Component* Createdcomp;
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x - Len / 2;
	GInfo.x2 = x + Len / 2;
	GInfo.y1 = y - Wdth / 2;
	GInfo.y2 = y + Wdth / 2;
	if (Name == "AND2")
	{
		Createdcomp = new AND2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "AND3")
	{
		Createdcomp = new AND3(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "BUFFER")
	{
		Createdcomp = new Buff(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "INVERTER")
	{
		Createdcomp = new INV(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "LED")
	{
		Createdcomp = new LED(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NAND2")
	{
		Createdcomp = new NAND2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NOR2")
	{
		Createdcomp = new NOR2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "NOR3")
	{
		Createdcomp = new NOR3(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "OR2")
	{
		Createdcomp = new OR2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "SWITCH")
	{
		Createdcomp = new Switch(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XNOR2")
	{
		Createdcomp = new XNOR2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XOR2")
	{
		Createdcomp = new XOR2(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else if (Name == "XOR3")
	{
		Createdcomp = new XOR3(GInfo, AND2_FANOUT);
		Createdcomp->SetLabel(label);
		Createdcomp->SetID(id);
		pManager->AddComponent(Createdcomp);
	}
	else
	{
		cout << "Gate Not found" << endl;
	}
}




void Load::Undo()
{
	
}

void Load::Redo()
{
}
