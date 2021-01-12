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
#include "Actions\SAVE.h"
#include<fstream>
#include<iostream>
#include "Actions\Delete.h"
#include "Actions\AddLabel.h"
#include "Actions\Edit.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\Move.h"
#include "Actions\ChangeSwitch.h"
#include "Actions\Simulate.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	ReSortCompList();
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
int ApplicationManager::GetCompCount()
{
	return CompCount;
}
void ApplicationManager::SetCompList(Component** rComponent)
{
	*CompList = *rComponent;
}
Component** ApplicationManager::GetCompList()
{
	return CompList;
}
void ApplicationManager::SaveComponent(ofstream& FILE)
{
	ReSortCompList();
	for (int i = 0; i < CompCount; i++)
		if(CompList[i])
		if (!dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(FILE);
}
void ApplicationManager::SaveConnection(ofstream& FILE)
{
	ReSortCompList();

	for (int i = 0; i < CompCount; i++)
		if(CompList[i])
		if (dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(FILE);
}

int ApplicationManager::GetConnCount()
{
	ReSortCompList();

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
		case COPY:
			pAct = new Copy(this);
			break;
		case ADD_Label:
			pAct = new AddLabel(this);
			break;
		case EDIT_Label:
			pAct = new Edit(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case MOVE:
			pAct = new Move(this);
			break;
		case SIMULATE:
			pAct = new Simulate(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case Change_Switch:
			pAct = new ChangeSwitch(this);
			break;
		case SAVE:
			pAct = new Save(this);
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
	//ReSortCompList();
	GetOutput()->ClearDrawingArea(); //Clears The drawing area before each update

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]) // checks if element is not nullified first
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
		if (CompList[i] != nullptr)
		{
			pin = CompList[i]->GetOutputpinCoordinates(x, y);
			if (pin != NULL)
			{
				return pin;
			}

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
		if (CompList[i] != nullptr)
		{
			pin = CompList[i]->GetInputpinCoordinates(x, y, index);
			if (pin != NULL)
			{
				return pin;
			}
		}
		
	}
	return NULL;
}
Component* ApplicationManager::GetCopied()
{
	return CopiedComponent;
}
void ApplicationManager::SetCopied(Component* c)
{
	// I only have one component to be copied or cut ...If I set copied Object then any other objects in the clipboard should be automatically deleted 
	if (CutComponent != NULL)
	{
		CutComponent = NULL;
	}
	if (CopiedComponent != NULL) // so as not to delete an object then assign copied component to it 
	{
		CopiedComponent = NULL;
	}

	CopiedComponent = c->MakeCopy(c);

}

Component* ApplicationManager::GetCut()
{
	return CutComponent;
}

void ApplicationManager::SetCut(Component* c)
{
	if (c == NULL) // If paste calls this fn to indicate that the cut-paste operation has been performed 
	{
		CutComponent = NULL;
		return;
	} // I only have one component to be copied or cut ...If I set Cut Object then any other objects in the clipboard should be automatically deleted 
	if (CopiedComponent != NULL)
	{

		CopiedComponent = NULL;
	}
	if (CutComponent != NULL)
	{

		CutComponent = NULL;
	}
	CutComponent = c->MakeCopy(c);
}

//puts nullified components out of the way and decrements componentcount value
void ApplicationManager::ReSortCompList()
{
	Component* rCompList[MaxCompCount];
	for (int i = 0; i < MaxCompCount; i++)
		rCompList[i] = nullptr;

	int NotDeletedCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
	{
		if (CompList[i])//checks if element is not nullified
		{
			rCompList[NotDeletedCount] = CompList[i]; //fills the complist with not nullified elements
			NotDeletedCount++;
		}
	}
	//Makes sure the remaining array elements are nullified
	for (int i = NotDeletedCount; i < MaxCompCount; i++)
	{
		rCompList[i] = nullptr;
	}
	
	CompCount = NotDeletedCount; //changes component counter
	SetCompList(rCompList); //updated array
}


ApplicationManager::~ApplicationManager()
{
	ReSortCompList();
	for(int i=0; i<CompCount; i++)
		if (CompList[i])
		{
			//delete CompList[i];
			CompList[i] = nullptr;
		}
	delete OutputInterface;
	delete InputInterface;
	
}