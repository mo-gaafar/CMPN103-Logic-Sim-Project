#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* CopiedComponent=NULL;
	Component* CutComponent=NULL;



public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window
	void SaveComponent(ofstream& PRINT);
	void SaveConnection(ofstream& PRINT);
	void getCompGraphicsLoad(int ID, GraphicsInfo& G1);


	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	OutputPin* GetOutputPin(int& x, int& y);
	InputPin* GetInputPin(int& x, int& y);
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	int GetCompCount(); //Gets number of total components 
	int GetConnCount(); //Gets number of connections
	void SetCompList(Component** s);
	void ReSortCompList();
	Component** GetCompList();
	Component* GetCopied();
	void SetCopied(Component* c);
	Component* GetCut();
	void SetCut(Component* c);
	InputPin* SearchIDINN(int ID);
	OutputPin* SearchIDOUT(int ID);
	void EmptyComplist();

	//destructor
	~ApplicationManager();
};

#endif