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
#include "Space.h"

#ifndef TORCHheartsACE_HPP
#define TORCHheartsACE_HPP

class TorchSpace
	: public Space
{
private:
	bool torchLit;

public:
	TorchSpace();
	TorchSpace(Space*, Space*, Space*, Space*);

	void describeSquare();

	void interactSpace();

	char showTorch();
};
#endif // !TORCHheartsACE_HPP
