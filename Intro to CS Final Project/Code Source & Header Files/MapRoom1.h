/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		First room in the dungeon. Spaces (5): 2 DoorSpaces, 2 
* TorchSpaces, and 1 EnemySpace. Enemies: mummy. Items: none. Constructor links
* and initializes variables. Includes a function to play rounds of travel/combat
* and print the map.
******************************************************************************/

#include "Space.h"
#include "doorSpace.h"
#include "torchSpace.h"
#include "EnemySpace.h"
#include "Mummy.h"

#ifndef MAPROOM1_HPP
#define MAPROOM1_HPP

class MapRoom1
{
	private:
	
		//labeled bottom up
		DoorSpace A1;
		TorchSpace A2;
		EnemySpace A3;
		TorchSpace A4;
		DoorSpace A5;

		Mummy mummy;				//enemy in A3

		int stepsRemaining;			//internal step counter

		int numTorchesLit;			//lighting all torches unlocks far door

		bool roomFinished;			
		
	public:
		MapRoom1(int*);							//links spaces in first room

		int navigateRoom1(Space*, Link*);		//Link explores the first room

		void printMap();						
};
#endif 