#include "AddLabel.h"
#include "..\ApplicationManager.h"

AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{

}


void AddLabel::Execute()
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
                GInfo = CompList[i]->GetCompInfo();
                LInfo.x1 = GInfo.x1;
                LInfo.y1 = GInfo.y1 - 20;

                pOut->PrintMsg("Enter component label: ");
                tempst = pIn->GetSrting(pOut);
                CompList[i]->SetLabel(tempst);
            }

    }

    pOut->ClearStatusBar();


}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}