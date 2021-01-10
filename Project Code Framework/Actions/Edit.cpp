#include "Edit.h"
#include "..\ApplicationManager.h"
#include "AddLabel.h"

Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
    pSrcPin = NULL;
    pDstPin = NULL;
    m_Connection = NULL;
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

                if (Component* c = dynamic_cast<Gate*> (CompList[i]))//checks if gate or connection
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

                    else if (tempst == "2") //Edits the connecition itself
                    {
                        //Print Action Message
                        pOut->PrintMsg("Edit connection: Select source pin");

                        //Wait for user input
                        pIn->GetPointClicked(m_GfxInfo.x1, m_GfxInfo.y1);
                        pSrcPin = pManager->GetOutputPin(m_GfxInfo.x1, m_GfxInfo.y1);

                        //Clear Status Bar
                        pOut->ClearStatusBar();

                        //Print Action Message
                        pOut->PrintMsg("Edit connection: Select destination pin");

                        //Wait for User Input
                        pIn->GetPointClicked(m_GfxInfo.x2, m_GfxInfo.y2);
                        pDstPin = pManager->GetInputPin(m_GfxInfo.x2, m_GfxInfo.y2);
                        
                        
                        //Set Source and DstPin
                        Connection* m_Connection = (Connection*)CompList[i];
                        m_Connection->setSourcePin(pSrcPin);
                        m_Connection->setDestPin(pDstPin);


                        //Clear Status Bar
                        pOut->ClearStatusBar();
                    }

                    else { pOut->PrintMsg("Wrong Input"); break; }
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