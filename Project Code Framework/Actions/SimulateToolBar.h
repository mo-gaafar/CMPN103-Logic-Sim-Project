#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class SimulateToolBar : public Action
{
private:
	int Cx, Cy;		// Point selected
public:
	/* Constructor */
	SimulateToolBar(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void  Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~SimulateToolBar();
};

