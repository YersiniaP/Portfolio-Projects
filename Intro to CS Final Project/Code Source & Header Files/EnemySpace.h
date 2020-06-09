/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Derived from Space Class. The other data member is a bool
* for the enemey status. A default constructor sets the pointers to null,
* while the other sets them to passed spaces. One function allows the character
* to interect the square, one to get a description of the square, and one to
* display the right letter on a map. There is also a getter and setter for the
* enemy bool.
******************************************************************************/
#include "Space.h"

#ifndef ENEMYheartsACE_HPP
#define ENEMYheartsACE_HPP

class EnemySpace : public Space
{
	private:
		bool hasEnemy;
	public:
		EnemySpace();
		EnemySpace(Space*, Space*, Space*, Space*);

		void describeSquare();
		void interactSpace();
		void setEnemyStatus(bool);
		bool getEnemyStatus();

		char showEnemy();
};
#endif