#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class GateToolBar : public Action
{
private:
	int Cx, Cy;		// Point selected
public:
	/* Constructor */
	GateToolBar(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void  Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~GateToolBar();
};

