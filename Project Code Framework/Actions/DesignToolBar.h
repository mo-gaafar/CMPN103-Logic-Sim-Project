#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class DesignToolBar : public Action
{
private:
	int Cx, Cy;		// Point selected
public:
	DesignToolBar(ApplicationManager* pAppMan);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//The action being executed
	virtual void  Execute();

	virtual void Undo();

	virtual void Redo();

	virtual ~DesignToolBar();
};

