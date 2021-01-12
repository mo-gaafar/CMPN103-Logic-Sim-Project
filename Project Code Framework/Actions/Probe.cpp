#include "Probe.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"

Probe::Probe(ApplicationManager* pApp) :Action(pApp)
{
}

Probe::~Probe(void)
{
}

void Probe::ReadActionParameters()
{
    //Get a Pointer to the Input / Output Interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    //Print Action Message
    pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

    //Wait for User Input
    pIn->GetPointClicked(Cx, Cy);

    //Clear Status Bar
    pOut->ClearStatusBar();

}


void Probe::Execute()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    pOut->PrintMsg("Select component");

    GraphicsInfo GInfo;
    Component** CompList = pManager->GetCompList();
    GraphicsInfo LInfo;
    string tempst;

    for (int i = 0; i < pManager->GetCompCount(); i++)
    {
        if (CompList[i] != NULL)
            if (CompList[i]->GetSelectedComponent() == true)
            {
                CompList[i]->SelectComponent(false);

                if (Component* c = dynamic_cast<Connection*> (CompList[i]))//checks if gate or connection
                {
                    
                }

            }
    }

    pOut->ClearStatusBar();

}

void Probe::Undo()
{}

void Probe::Redo()
{}

