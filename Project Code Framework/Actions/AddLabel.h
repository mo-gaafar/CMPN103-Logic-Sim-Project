#ifndef _ADD_AND_LABEL_H
#define _ADD_AND_LABEL_H

#include "action.h"
#include "..\Components\AND2.h"

class AddLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddLabel(ApplicationManager* pApp);
	virtual ~AddLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	//virtual void AddLabel();
	virtual void Undo();
	virtual void Redo();


};

#endif