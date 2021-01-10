#pragma once
#include "action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
class Copy :public Action
{
	Component* Copied;
public:
	Copy(ApplicationManager* pManager);
	virtual ~Copy();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};