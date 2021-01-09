#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"

class Select : public Action
{
private:
	int Cx, Cy;		// Point selected
	Component* Comp;
public:
	Select(ApplicationManager* pAppMan);

	//Reads required parameters for action to execute
	virtual void ReadActionParameters();
	//Action execution
	virtual void  Execute();

	virtual void Undo();

	virtual void Redo();

	virtual ~Select();
};

