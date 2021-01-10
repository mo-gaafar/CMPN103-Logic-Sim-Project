#include "Cut.h"

Cut::Cut(ApplicationManager* pManager) :Action(pManager)
{
	Copied = NULL;
}

Cut::~Cut()
{
}

void Cut::ReadActionParameters()
{
}

void Cut::Execute()
{
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
