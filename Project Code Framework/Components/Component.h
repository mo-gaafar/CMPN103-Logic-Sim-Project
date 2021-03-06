#ifndef _COMPONENT_H
#define _COMPONENT_H
class ApplicationManager;
#include<iostream>
#include<ostream>
#include<istream>
#include<fstream>

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "OutputPin.h"
#include "InputPin.h"

//Base class for classes Gate, Switch, and LED.
class Component
{

protected:
	bool Selected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	string m_Label; //text in label
	bool Changed;
	int ID; //Unique id of component
public:
	Component(GraphicsInfo& r_GfxInfo);
	Component();
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself

	// Sets the label of the component
	void SetLabel(const string& label);

	// Returns the label of the component
	string GetLabel() const;
	void SetID(int i);
	int GetID();
	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1
	
	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.

	virtual OutputPin* GetOutputpinCoordinates(int& X_Out, int& Y_Out) = 0; //gets rectangular range of output pin given click coordinates, returns pointer to the selected gate's output pin element
	virtual InputPin* GetInputpinCoordinates(int& X_In, int& Y_In, int& n_Input)=0;//gets rectangular range of input pin (changes depending on gate location) returns Index and InputPin array pointer
	bool IsID(int i);
	
	void SetCompInfo(GraphicsInfo& g);
	//Sets the selection of the component 
	virtual void SelectComponent(bool s);
	virtual void ChangeGate(bool c);
	//Checks if component is selected or not
	bool GetSelectedComponent();
	bool GetChangedGate();
	virtual Component* MakeCopy(Component*) = 0;
	GraphicsInfo* GetGraphicsInfo();//Returns gfxinfo struct
	GraphicsInfo GetCompInfo();
	virtual void Save(ofstream& print) = 0;
	virtual GraphicsInfo& GetgraphInfo();

	virtual OutputPin* getSourcePin();//polymorphic function to get source pin from array element


	//Destructor must be virtual
	virtual ~Component();
};

#endif
