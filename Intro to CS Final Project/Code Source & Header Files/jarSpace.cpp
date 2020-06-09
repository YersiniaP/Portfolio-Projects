/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. The other data member is a bool
* for the jar status. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. One function allows the character
* to interect the square, one to get a description of the square, and two to
* display the right letter on a map. There is also a getter for the jarOpened bool.
******************************************************************************/
#include <iostream>
#include "Space.h"
#include "jarSpace.h"

using std::cout;
using std::endl;

/******************************************************************************
*							JarSpace::JarSpace - Default
* Initializes the pointers to nullptr
******************************************************************************/
JarSpace::JarSpace()
{
	up = down = left = right = nullptr;
	jarOpened = false;
}

/******************************************************************************
*							JarSpace::JarSpace
* Initializes the pointers to passed pointers. jar unopened by default.
******************************************************************************/
JarSpace::JarSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare)
	: Space(upSquare, downSquare, leftSquare,  rightSquare)
{
	jarOpened = false;
}

/******************************************************************************
*							JarSpace::describeSquare
* Prints a space description to user.
******************************************************************************/
void JarSpace::describeSquare()
{
	cout << "There is a jar in the corner of this space." << endl;
}

/******************************************************************************
*							JarSpace::interactSpace
* Opens jar.
******************************************************************************/
void JarSpace::interactSpace()
{
	jarOpened = true;
}

/******************************************************************************
*							JarSpace::showDoor
* How a square is printed on a map if jar is opened or not.
******************************************************************************/
char JarSpace::showJar()
{
	if (jarOpened)
	{
		return 'j';
	}
	else
	{
		return 'J';
	}
}

/******************************************************************************
*							JarSpace::showDoor
* How a square is printed on a map if jar hides a switch or not.
******************************************************************************/
char JarSpace::showJar(bool secretSwitch)
{
	if (secretSwitch)
	{
		return 'o';
	}
	else
	{
		if (jarOpened)
		{
			return 'j';
		}
		else
		{
			return 'J';
		}
	}
}

//getter for jarOpened
bool JarSpace::jarStatus()
{
	return jarOpened;
}
