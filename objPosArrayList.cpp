#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList == sizeArray)          //if size list is full 
    return;

    for(int i=sizeList; i>0; i--)     //shift list elements towards tail
        aList[i] = aList[i-1];
    aList[0] = thisPos;               //insert pos at head
    sizeList++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)
    return;

    aList[sizeList++] = thisPos;       //inset pos at tail end
}

void objPosArrayList::removeHead()
{
    if(sizeList == 0)                   //if theres nothing in list, nothing to remove
    return;

    for(int i=0; i<sizeList-1l; i++)
        aList[i] = aList[i+1];           //shift elements towards head
    sizeList--;

}

void objPosArrayList::removeTail()
{
    if(sizeList == 0)
    return;

    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    //return through pass by reference
    returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos = aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos = aList[index];
}

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList == sizeArray)          //if size list is full 
    return;

    for(int i=sizeList; i>0; i--)     //shift list elements towards tail
        aList[i] = aList[i-1];
    aList[0] = thisPos;               //insert pos at head
    sizeList++;

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)
    return;

    aList[sizeList++] = thisPos;       //inset pos at tail end
}

void objPosArrayList::removeHead()
{
    if(sizeList == 0)                   //if theres nothing in list, nothing to remove
    return;

    for(int i=0; i<sizeList-1l; i++)
        aList[i] = aList[i+1];           //shift elements towards head
    sizeList--;

}

void objPosArrayList::removeTail()
{
    if(sizeList == 0)
    return;

    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    //return through pass by reference
    returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos = aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos = aList[index];
}