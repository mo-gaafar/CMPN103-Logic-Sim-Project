#ifndef _PROBE_H
#define _PROBE_H

#include "action.h"
#include "..\Components\AND2.h"

class Probe : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	Probe(ApplicationManager* pApp);
	virtual ~Probe(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif