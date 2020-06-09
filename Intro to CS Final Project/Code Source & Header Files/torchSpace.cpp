/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. The other data member is a bool
* for the torch status. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. One function allows the character
* to interect the square, one to get a description of the square, and one to
* display the right letter on a map.
******************************************************************************/
#include <iostream>
#include "Space.h"
#include "torchSpace.h"

using std::cout;
using std::endl;

/******************************************************************************
*							TorchSpace::TorchSpace - Default
* Initializes the pointers to nullptr
******************************************************************************/
TorchSpace::TorchSpace()
{
	up = down = left = right = nullptr;
	torchLit = false;
}

/******************************************************************************
*							TorchSpace::TorchSpace
* Initializes the pointers to passed pointers. Torch unlit by default.
******************************************************************************/
TorchSpace::TorchSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare)
	: Space(upSquare, downSquare, leftSquare, rightSquare)
{
	torchLit = false;
}

/******************************************************************************
*							TorchSpace::describeSquare
* Prints a space description to user.
******************************************************************************/
void TorchSpace::describeSquare()
{
	cout << "There are two torches in this square" << endl;
}

/******************************************************************************
*							TorchSpace::interactSpace
* Lights torches
******************************************************************************/
void TorchSpace::interactSpace()
{
	torchLit = true;
	cout << "These torches are lit" << endl;
}
/******************************************************************************
*							TorchSpace::showTorch
* How a square is printed on a map if torch is lit or not.
******************************************************************************/
char TorchSpace::showTorch()
{
	if (torchLit)
	{
		return 'T';
	}
	else
	{
		return 't';
	}
}
