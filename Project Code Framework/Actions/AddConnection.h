#ifndef _ADD_CONNECTION_COMPONENT_H
#define _ADD_CONNECTION_COMPONENT_H

#include "../Actions/Action.h"
#include "../Components/Connection.h"
#include "../ApplicationManager.h"
#include "../Defs.H"
#include "../Components/Pin.h"

class AddConnection : public Action
{
private:
	OutputPin* pSrcPin;
	InputPin* pDstPin;
	GraphicsInfo m_GfxInfo;
	Connection* m_Connection;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection();


	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};


#endif
