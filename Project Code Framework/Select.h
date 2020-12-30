#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "Components\Component.h"

class Select : public Action
{
private:
	int Cx, Cy;		// Point selected
	Component* Comp;
public:
	/* Constructor */
	Select(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual void  Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Select();
};

