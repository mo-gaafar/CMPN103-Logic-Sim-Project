#include "../Actions/AddConnection.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
	pSrcPin = NULL;
	pDstPin = NULL;
	m_Connection = NULL;
}

AddConnection::~AddConnection()
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Add connection: Select source pin");

	//Wait for User Input
	pIn->GetPointClicked(m_GfxInfo.x1, m_GfxInfo.y1);
	pSrcPin = pManager->GetOutputPin(m_GfxInfo.x1, m_GfxInfo.y1);

	//Clear Status Bar
	pOut->ClearStatusBar();

	//Print Action Message
	pOut->PrintMsg("Add connection: Select destination pin");

	//Wait for User Input
	pIn->GetPointClicked(m_GfxInfo.x2, m_GfxInfo.y2);
	pDstPin = pManager->GetInputPin(m_GfxInfo.x2, m_GfxInfo.y2);

	

	//Clear Status Bar
	pOut->ClearStatusBar();
}

//Draw connection
void AddConnection::Execute()
{


	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	//Checks if click is not within drawing area
	if ((m_GfxInfo.y2 < UI.ToolBarHeight && m_GfxInfo.x2 < UI.ToolItemWidth * ITM_DSN_CNT)||
		(m_GfxInfo.y1 < UI.ToolBarHeight && m_GfxInfo.x1 < UI.ToolItemWidth * ITM_DSN_CNT))
	{
		pOut->PrintMsg("Error, you have to draw within the drawing area");
	}
	else {
		if (pSrcPin != NULL && pDstPin != NULL)
		{
			m_Connection = new Connection(m_GfxInfo, pSrcPin, pDstPin);
			m_Connection->setSourcePin(pSrcPin);
			m_Connection->setDestPin(pDstPin);
			m_Connection->setDestPinIndex(pDstPin->getIndex());
			pManager->AddComponent(m_Connection);
			pOut->ClearStatusBar();
		}
		else
			pOut->PrintMsg("Error, pins not properly selected");

	}
}

void AddConnection::Undo()
{}

void  AddConnection::Redo()
{}

