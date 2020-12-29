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

	//Clear Status Bar
	pOut->ClearStatusBar();

	//Print Action Message
	pOut->PrintMsg("Add connection: Select destination pin");

	//Wait for User Input
	pIn->GetPointClicked(m_GfxInfo.x2, m_GfxInfo.y2);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

//Draw connection
void AddConnection::Execute()
{

	ReadActionParameters();

 Connection* m_Connection = new Connection(m_GfxInfo, pSrcPin, pDstPin);
	m_Connection->setSourcePin(pSrcPin);
	m_Connection->setDestPin(pDstPin);
	pManager->AddComponent(m_Connection);

}