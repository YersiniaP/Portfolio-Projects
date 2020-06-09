/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. The other data member is a bool
* for the door status. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. One function allows the character
* to interect the square, one to get a description of the square, and one to
* display the right letter on a map. There is also a getter for the locked bool.
******************************************************************************/
#include "Space.h"
#ifndef DOORheartsACE_HPP
#define DOORheartsACE_HPP

class DoorSpace : public Space
{
private:
	bool locked;

public:
	DoorSpace();
	DoorSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare);

	void describeSquare();
	void interactSpace();

	bool getLockStatus();

	char showDoor();
};
#endif 