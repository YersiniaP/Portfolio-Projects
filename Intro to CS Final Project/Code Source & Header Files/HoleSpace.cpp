/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. No other data members. A default
* constructor sets the pointers to null, while the other sets them to passed
* spaces. One function allows the character to interect the square and the
* other to get a description of the square
******************************************************************************/
#include <iostream>
#include "HoleSpace.h"

using std::cout;
using std::endl;

/******************************************************************************
*							HoleSpace::HoleSpace - Default
* Initializes the pointers to nullptr
******************************************************************************/
HoleSpace::HoleSpace()
{
	up = down = left = right = nullptr;
}

/******************************************************************************
*							HoleSpace::HoleSpace
* Initializes the pointers to passed pointers. 
******************************************************************************/
HoleSpace::HoleSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare)
	: Space(upSquare, downSquare, leftSquare, rightSquare)
{

}

/******************************************************************************
*							HoleSpace::describeSquare
* Prints a space description to user.
******************************************************************************/
void HoleSpace::describeSquare()
{
	cout << "There is a gaping hole in this space." << endl;
}

/******************************************************************************
*							HoleSpace::interactSpace
* Displays stars representing a fall down a deep hole.
******************************************************************************/
void HoleSpace::interactSpace()
{
	cout << "You jump into the hole." << endl;

	cout << " * * * * * * * * * * * * * * * *" << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << " * * * * * * * * * * * * * * * *" << endl;
		cout << "* * * * * * * * * * * * * * * * *" << endl;
		cout << " * * * * * * * * * * * * * * * *" << endl;
	}
}
