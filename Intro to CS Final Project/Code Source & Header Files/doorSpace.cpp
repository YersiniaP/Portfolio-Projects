/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. The other data member is a bool
* for the soor status. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. One function allows the character
* to interect the square, one to get a description of the square, and one to
* display the right letter on a map. There is also a getter for the locked bool.
******************************************************************************/
#include <iostream>
#include "Space.h"
#include "doorSpace.h"

using std::cout;
using std::endl;

/******************************************************************************
*							DoorSpace::DoorSpace - Default
* Initializes the pointers to nullptr
******************************************************************************/
DoorSpace::DoorSpace()
{
	up = down = left = right = nullptr;
	locked = true;
}

/******************************************************************************
*							DoorSpace::DoorSpace
* Initializes the pointers to passed pointers. Door locked by default.
******************************************************************************/
DoorSpace::DoorSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare)
	: Space (upSquare, downSquare, leftSquare, rightSquare)
{
	locked = true;
}

/******************************************************************************
*							DoorSpace::describeSquare
* Prints a space description to user.
******************************************************************************/
void DoorSpace::describeSquare()
{
	cout << "There is a ";

	if (!locked)
	{
		cout << "un";
	}
		
	cout << "locked door in this space" << endl;
}

/******************************************************************************
*							DoorSpace::interactSpace
* Unlocks door. 
******************************************************************************/
void DoorSpace::interactSpace()
{
	locked = false;
}

//getter for locked data member
bool DoorSpace::getLockStatus()
{
	return locked;
}

/******************************************************************************
*							DoorSpace::showDoor
* How a square is printed on a map if door is locked or not.
******************************************************************************/
char DoorSpace::showDoor()
{
	if (locked)
	{
		return 'D';
	}
	else
	{
		return 'd';
	}
}