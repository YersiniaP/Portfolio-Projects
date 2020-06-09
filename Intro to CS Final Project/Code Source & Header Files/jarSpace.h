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
#include "Space.h"

#ifndef JARheartsACE_HPP
#define JARheartsACE_HPP


class JarSpace :
	public Space
{
	private:
		bool jarOpened;

	public:
		JarSpace();
		JarSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare);

		void describeSquare();
		void interactSpace();

		char showJar();
		char showJar(bool);			//overload to show switch on map

		bool jarStatus();
};
#endif // !JARheartsACE_HPP
