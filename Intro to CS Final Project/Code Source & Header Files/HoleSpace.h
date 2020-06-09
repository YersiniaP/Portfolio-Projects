/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. No other data members. A default
* constructor sets the pointers to null, while the other sets them to passed 
* spaces. One function allows the character to interect the square and the 
* other to get a description of the square
******************************************************************************/
#include "Space.h"

#ifndef HOLESPACE_HPP
#define HOLESPACE_HPP

class HoleSpace : public Space
{
	private:

	public:
		HoleSpace();
		HoleSpace(Space*, Space*, Space*, Space*);

		void describeSquare();

		void interactSpace();

};
#endif
