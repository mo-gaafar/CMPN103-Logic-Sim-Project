#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class DesignToolBar : public Action
{
private:
	int Cx, Cy;		// Point selected
public:
	/* Constructor */
	DesignToolBar(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void  Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~DesignToolBar();
};

