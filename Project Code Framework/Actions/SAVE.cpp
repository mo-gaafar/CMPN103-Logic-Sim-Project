#include "../Actions/SAVE.h"
#include "../ApplicationManager.h"
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;
Save::Save(ApplicationManager* pApp) : Action(pApp)
{

}

Save::~Save()
{

}

void Save::ReadActionParameters()
{
}

void Save::Execute()
{

	string fileName = "data.txt";
	ofstream print(fileName);
	print << pManager->GetCompCount() << endl; //Prints number of total components
	pManager->SaveComponent(print);
	print << "Connections" << endl;
	pManager->SaveConnection(print);
	pManager->GetOutput()->PrintMsg("File has been saved by name " + fileName);
	print << -1;
	print.close();
}

void Save::Undo()
{
}

void Save::Redo()
{
}

