/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Second room in the dungeon. Spaces (4): 2 DoorSpaces, and 2
* JarSpaces. Enemies: snakes. Items: key, redPotion. Constructor links
* and initializes variables. Includes a function to play rounds of travel/combat
* and print the map. A secret switch is under the B2 jar and triggers snakes.
******************************************************************************/
#include "Space.h"
#include "doorSpace.h"
#include "JarSpace.h"
#include "EnemySpace.h"
#include "Item.h"
#include "Link.h"
#include "Snakes.h"

#ifndef MAPROOM2_HPP
#define MAPROOM2_HPP

class MapRoom2
{
	private:

		//labeled clockwise from bottom left
		DoorSpace B1;
		JarSpace B2;
		DoorSpace B3;
		JarSpace B4;

		Snakes snakes;

		Item key;		//pointer to key item
		Item potion;

		int stepsRemaining;
		bool switchTriggered;
		bool roomFinished;
		
	public:
		MapRoom2(int*);

		int navigateRoom2(Space*, Link*);

		void printMap();
};
#endif