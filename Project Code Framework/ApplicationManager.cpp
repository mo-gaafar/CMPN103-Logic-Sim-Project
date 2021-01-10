#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddBuff.h"
#include "Actions\AddINV.h"
#include "Actions\AddLED.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddConnection.h"
#include "Actions\Select.h"
#include "Actions\SimulateToolBar.h"
#include "Actions\DesignToolBar.h"
#include "Actions\GateToolBar.h"
#include "Actions\ExitProgram.h"
#include "SAVE.h"
#include<fstream>
#include<iostream>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCompCount()
{
	return CompCount;
}
void ApplicationManager::SetCompList(Component** l)
{
	*CompList = *l;
}
Component** ApplicationManager::GetCompList()
{
	return CompList;
}
void ApplicationManager::SaveComponent(ofstream& FILE)
{
	for (int i = 0; i < CompCount; i++)
		if (!dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->SAVE(FILE);
}
void ApplicationManager::SaveConnection(ofstream& FILE)
{
	for (int i = 0; i < CompCount; i++)
		if (dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->SAVE(FILE);
}

int ApplicationManager::connectionNumber()
{
	int count = 0;
	for (int i = 0; i < CompCount; i++)
		if (!dynamic_cast<Connection*>(CompList[i]))
			count++;
	return count;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_Buff:
			pAct = new AddBuff(this);
			break;
		case ADD_INV:
			pAct = new AddINV(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case SIM_MODE:
			pAct = new SimulateToolBar(this);
			break;
		case DSN_MODE:
			pAct = new DesignToolBar(this);
			break;
		case SELECT_AREA:
			pAct = new Select(this);
			break;
		case GATE_MODE:
			pAct = new GateToolBar(this);
			break;
		case EXIT:
			pAct = new ExitProgram(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Draw(OutputInterface);
		
	}

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

//Returns outputpin pointer
OutputPin* ApplicationManager::GetOutputPin(int& x, int& y)
{
	OutputPin* pin = NULL;

	for (int i = 0; i < CompCount; i++)
	{
		pin = CompList[i]->GetOutputpinCoordinates(x, y);
		if (pin != NULL)
		{
			return pin;
		}

	}
	return NULL;
}

InputPin* ApplicationManager::GetInputPin(int& x, int& y)
{
	int index;
	InputPin* pin = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		pin = CompList[i]->GetInputpinCoordinates(x, y, index);
		if (pin != NULL)
		{
			return pin;
		}
	}
	return NULL;
}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}