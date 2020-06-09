/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		The Space Class has 4 pointers (to other spaces) representing
*					up, down, left, and right. The other data member is a bool
* for map printing purposes. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. Two virtual abstract functions
* are overridden in derived classes. Two other functions facilitate the map
* representation of the square. The remaining functions are pointer getters.
******************************************************************************/
#include "Space.h"

/******************************************************************************
*							Space::Space - Default
* Initializes the pointers to nullptr
******************************************************************************/
Space::Space()
{
	up = down = left = right = nullptr;
	hasLink = false;
}

/******************************************************************************
*							Space::Space
* Initializes the pointers to passed pointers.
******************************************************************************/
Space::Space(Space* upSquare, Space* downSquare, Space *leftSquare, Space* rightSquare)
{
	up = upSquare;
	down = downSquare;
	right = rightSquare;
	left = leftSquare;	

	hasLink = false;
}

//pointer setters
void Space::setRight(Space* rightSquare)
{
	right = rightSquare;
}

void Space::setLeft(Space* leftSquare)
{
	left = leftSquare;
}

void Space::setUp(Space* upSquare)
{
	up = upSquare;
}

void Space::setDown(Space* downSquare)
{
	down = downSquare;
}
/******************************************************************************
*							Space::toggleLink
* Toggles the hasLink variable (for map printing).
******************************************************************************/
void Space::toggleLink()
{
	if (hasLink)
	{
		hasLink = false;
	}
	else
	{
		hasLink = true;
	}
}

/******************************************************************************
*							Space::showLink
* How a square is printed on a map if Link is there or not.
******************************************************************************/
char Space::showLink()
{
	if (hasLink)
	{
		return 'L';
	}
	else
	{
		return ' ';
	}
}

//pointer getters
Space* Space::moveRight()
{
	return right;
}

Space* Space::moveLeft()
{
	return left;
}

Space* Space::moveUp()
{
	return up;
}

Space* Space::moveDown()
{
	return down;
}
