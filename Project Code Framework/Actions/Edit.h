#ifndef _EDIT_H
#define _EDIT_H

#include "action.h"
#include "..\Components\AND2.h"
#include "AddConnection.h"
class Edit : public Action
{
private:
    OutputPin* pSrcPin;
    InputPin* pDstPin;
    GraphicsInfo m_GfxInfo;
    Connection* m_Connection;
    //Parameters for rectangular area to be occupied by the gate
    int Cx, Cy;    //Center point of the gate
    int x1, y1, x2, y2;    //Two corners of the rectangluar area
public:
    Edit(ApplicationManager* pApp);
    virtual ~Edit(void);

    //Reads parameters required for action to execute
    virtual void ReadActionParameters();
    //Execute action (code depends on action type)
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();


};

#endif