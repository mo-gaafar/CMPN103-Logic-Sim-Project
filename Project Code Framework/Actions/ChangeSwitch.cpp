#include "ChangeSwitch.h"
#include "..\ApplicationManager.h"
#include "..\Components\Switch.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ChangeSwitch::~ChangeSwitch(void)
{
}

void ChangeSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


void ChangeSwitch::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Select desired switch ");

    GraphicsInfo GInfo;
    Component** CompList = pManager->GetCompList();

    for (int i = 0; i < pManager->GetCompCount(); i++)
    {
        if (CompList[i] != NULL && (CompList[i]->GetSelectedComponent() == true))
			if (CompList[i]->GetChangedGate() == 1)
			{

				if (Component* c = dynamic_cast<Switch*> (CompList[i]))
				{
					CompList[i]->SelectComponent(false);
					//GInfo = CompList[i]->GetCompInfo();
					CompList[i]->ChangeGate(0);
					//CompList[i]->setInputPinStatus(1, HIGH);

				}
			}
			else if (CompList[i]->GetChangedGate() == 0)
			{
				if (Component* c = dynamic_cast<Switch*> (CompList[i]))
				{
					CompList[i]->SelectComponent(false);
					//GInfo = CompList[i]->GetCompInfo();
					CompList[i]->ChangeGate(1);
					//CompList[i]->setInputPinStatus(1, HIGH);

				}
			}

    }

    pOut->ClearStatusBar();


	/*else {

		pOut->ClearStatusBar();
		Adds the component to the complist
		AND2* pA = new AND2(GInfo, AND2_FANOUT);
		pManager->AddComponent(pA);

	}*/

}

void ChangeSwitch::Undo()
{}

void ChangeSwitch::Redo()
{}

