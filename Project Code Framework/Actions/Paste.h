#pragma once
#include "Action.h"
#include "..\Components\Component.h"

class Paste :public Action
{
	Component* Copied;
public:
	Paste(ApplicationManager* pManager);
	virtual ~Paste();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

