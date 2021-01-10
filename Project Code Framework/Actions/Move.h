#pragma once
#include "action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
class Move :public Action
{
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* Comp;

public:
	Move(ApplicationManager* pManager);
	virtual ~Move();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};