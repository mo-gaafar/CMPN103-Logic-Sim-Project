#include "Edit.h"
#include "..\ApplicationManager.h"
#include "AddLabel.h"

Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{

}


void Edit::Execute()
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

                if (Component* c = dynamic_cast<Gate*> (CompList[i]))
                {
                    pManager->ExecuteAction(ADD_Label); //Edits label
                }

                else
                {
                    pOut->PrintMsg("Enter 1 to edit Connection's label OR 2 to edit it's pins");
                    tempst = pIn->GetSrting(pOut);

                    if (tempst == "1")
                    {
                        pManager->ExecuteAction(ADD_Label); //Edits connection label
                    }

                    else if (tempst == "2")
                    {
                        
                    }

                    else break;
                }


                GInfo = CompList[i]->GetCompInfo();
                LInfo.x1 = GInfo.x1;
                LInfo.y1 = GInfo.y1 - 20;

                pOut->PrintMsg("Enter component label: ");
                tempst = pIn->GetSrting(pOut);
                CompList[i]->SetLabel(tempst);
                //pOut->DrawString(LInfo, tempst);
            }

    }

    pOut->ClearStatusBar();


}

void Edit::Undo()
{}

void Edit::Redo()
{}