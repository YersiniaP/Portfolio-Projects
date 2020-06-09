/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Third room in the dungeon. Spaces (4): 1 DoorSpace, 1
* JarSpace, 1 EnemySpace, 1 HoleSpace. Enemies: mummy. Items: redPotion. 
* Constructor links and initializes variables. Includes a function to play 
* rounds of travel/combat and print the map. Jumping into the holes is the way
* to the next room.
******************************************************************************/
#include "Space.h"
#include "doorSpace.h"
#include "JarSpace.h"
#include "EnemySpace.h"
#include "HoleSpace.h"
#include "Item.h"
#include "Link.h"
#include "Mummy.h"

#ifndef MAPROOM3_HPP
#define MAPROOM3_HPP

class MapRoom3
{
private:

	//pointers to spaces
	//labeled clockwise from bottom left
	EnemySpace C1;
	DoorSpace C2;;
	HoleSpace C3;
	JarSpace C4;

	Mummy mummy;

	Item potion;

	int stepsRemaining;
	bool roomFinished;

public:
	MapRoom3(int*);

	int navigateRoom3(Space*, Link*);

	void printMap();
};
#endif