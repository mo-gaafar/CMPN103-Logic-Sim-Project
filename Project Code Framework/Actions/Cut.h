#pragma once
#include "Action.h"
#include "..\Components\Component.h"

class Cut :public Action
{
	Component* Copied; //Might need to edit some stuff
public:
	Cut(ApplicationManager* pManager);
	virtual ~Cut();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
