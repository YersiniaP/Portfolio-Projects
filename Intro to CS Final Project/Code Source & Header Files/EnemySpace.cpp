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
#include <iostream>
#include "Space.h"
#include "EnemySpace.h"

using std::cout;
using std::endl;

/******************************************************************************
*							EnemySpace::EnemySpace - Default
* Initializes the pointers to nullptr
******************************************************************************/
EnemySpace::EnemySpace()
{
	up = down = left = right = nullptr;
	hasEnemy = true;
}

/******************************************************************************
*							EnemySpace::EnemySpace
* Initializes the pointers to passed pointers. Enemy present by default.
******************************************************************************/
EnemySpace::EnemySpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare)
	: Space(upSquare, downSquare, leftSquare, rightSquare)
{
	hasEnemy = true;
}

/******************************************************************************
*							EnemySpace::describeSquare
* Prints a space description to user.
******************************************************************************/
void EnemySpace::describeSquare()
{
	cout << "There is an enemy in this square" << endl;
}

void EnemySpace::interactSpace()
{
	//not used
}

//setter for hasEnemy
void EnemySpace::setEnemyStatus(bool enemyAlive)
{
	hasEnemy = enemyAlive;
}

//getter for hasEnemy
bool EnemySpace::getEnemyStatus()
{
	return hasEnemy;
}

/******************************************************************************
*							EnemySpace::showEnemy
* How a square is printed on a map if enemy is there or not.
******************************************************************************/
char EnemySpace::showEnemy()
{
	if (hasEnemy)
	{
		return 'm';
	}
	else
	{
		return ' ';
	}
}