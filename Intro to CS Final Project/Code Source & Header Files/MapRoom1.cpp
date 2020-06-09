/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		First room in the dungeon. Spaces (5): 2 DoorSpaces, 2
* TorchSpaces, and 1 EnemySpace. Enemies: mummy. Items: none. Constructor links
* and initializes variables. Includes a function to play rounds of travel/combat
* and print the map.
******************************************************************************/
#include <iostream>
#include "Link.h"
#include "MapRoom1.h"
#include "inputValid.hpp"

using std::cout;
using std::endl;

/******************************************************************************
*							MapRoom1::MapRoom1
* Contructor to link spaces and initialize variables. Places link in first space
* on map. Takes step counter as a parameter.
******************************************************************************/
MapRoom1::MapRoom1(int *steps)
{
	A1 = DoorSpace(&A2, nullptr, nullptr, nullptr);
	A2 = TorchSpace(&A3, &A1, nullptr, nullptr);
	A3 = EnemySpace(&A4, &A2, nullptr, nullptr);
	A4 = TorchSpace(&A5, &A3, nullptr, nullptr);
	A5 = DoorSpace(nullptr, &A4, nullptr, nullptr);

	A1.toggleLink();		//Link position on map

	roomFinished = false;

	numTorchesLit = 0;

	stepsRemaining = *steps;  //step counter
}

/******************************************************************************
*							MapRoom1::navigateRoom1
* Allows player to traverse room with Space pointers. Player pointer moves along
* the Spaces while the character interacts with enemies/items. A menu prompts at
* the start of each space and the counter increased at the end. Room is finished
* by lighting all torches and exiting through the top door.
******************************************************************************/
int MapRoom1::navigateRoom1(Space* LinkPtr, Link* player)
{
	LinkPtr = &A1;
	while (!roomFinished && stepsRemaining > 0)
	{
		printMap(); //print map at the beginning of each step

		LinkPtr->describeSquare();

		if (LinkPtr == &A1) //Options for first square
		{
			cout << "What would you like to do?" << endl;
			cout << " 1) Move up a square" << endl;

			string choose = "Please enter 1";
			int choice = inputValid(choose, 1, 1);

			if (choice == 1)
			{
				LinkPtr = A1.moveUp();		//move Link to square above (A2)
			}
			A1.toggleLink();				//removes Link from first space on map
			LinkPtr->toggleLink();			//adds Link to second space on map
			stepsRemaining--;				//step counter decremented
		}
		else if(LinkPtr == &A2)
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move up a square" << endl;
			cout << " 2) Move down a square" << endl;
			cout << " 3) Light the torches with your Lamp" << endl;

			string choose = "Please enter 1, 2, or 3";

			int choice = inputValid(choose, 1, 3);
			if (choice == 1)
			{
				LinkPtr->toggleLink();
				LinkPtr = A2.moveUp();
				LinkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				LinkPtr->toggleLink();
				LinkPtr = A2.moveDown();
				LinkPtr->toggleLink();
			}
			else  //choice == 3
			{
				LinkPtr->interactSpace();  //lights torches
				numTorchesLit++;
			}

			if (numTorchesLit == 2)		//if all torches lit
			{ 
				cout << "*" << endl;
				cout << " * You hear a faint metallic scraping noise ahead * " << endl;
				cout << "*" << endl;
				A5.interactSpace();		//Lighting all torches unlocks far door
			}
			stepsRemaining--;
		}
		else if (LinkPtr == &A3)
		{
			if (A3.getEnemyStatus()) //Link must fight mummy upon enter square
			{
				cout << "Link fights mummy" << endl;
				while (mummy.getStatus())
				{
					mummy.defend(player->launchAttack()); //Link attacks first
					if (mummy.getStatus())
					{
						player->defend(mummy.launchAttack());  //mummy attacks back if survives
					}
					if (!player->getStatus())	//if player dies
					{
						cout << "You've died!" << endl;
						stepsRemaining = 0;
						return stepsRemaining;
					}
				}
				A3.setEnemyStatus(false);  // space no longer has enemy
			}
			else
			{
				cout << "What would you like to do?" << endl;

				cout << " 1) Move up a square" << endl;
				cout << " 2) Move down a square" << endl;
				string choose = "Please enter 1, or 2";

				int choice = inputValid(choose, 1, 2);

				LinkPtr->toggleLink();	  //removes Link from old square on map

				if (choice == 1)
				{
					LinkPtr = A3.moveUp();
				}
				else //(choice == 2)
				{
					LinkPtr = A1.moveDown();
				}

				LinkPtr->toggleLink();		//adds Link to new square on map
			}
			stepsRemaining--;
		}
		else if (LinkPtr == &A4)
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move up a square" << endl;
			cout << " 2) Move down a square" << endl;
			cout << " 3) Light the torches with your Lamp" << endl;

			string choose = "Please enter 1, 2, or 3";

			int choice = inputValid(choose, 1, 3);
			if (choice == 1)
			{
				LinkPtr->toggleLink();
				LinkPtr = A4.moveUp();
				LinkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				LinkPtr->toggleLink();
				LinkPtr = A4.moveDown();
				LinkPtr->toggleLink();
			}
			else  //choice == 3
			{
				LinkPtr->interactSpace();			//lights torches in this square
				numTorchesLit++;
			}

			if (numTorchesLit == 2)
			{
				cout << "*" << endl;
				cout << " * You hear a faint metallic scraping noise ahead * " << endl;
				cout << "*" << endl;

				A5.interactSpace();
			}
			stepsRemaining--;
		}
		else if (LinkPtr == &A5)
		{
			if (A5.getLockStatus()) //player must light torches to unlock door
			{
				cout << "What would you like to do?" << endl;

				cout << " 1) Move down a square" << endl;

				string choose = "Please enter 1";
				int choice = inputValid(choose, 1, 1);
				if (choice == 1)
				{
					LinkPtr->toggleLink();
					LinkPtr = A5.moveDown();
					LinkPtr->toggleLink();
				}
			}
			else
			{
				cout << "What would you like to do?" << endl;
				cout << " 1) Open the door and go into the next room" << endl;

				string choose = "Please enter 1";
				int choice = inputValid(choose, 1, 1);
				
				roomFinished = true; //exits Room 1
			}
			stepsRemaining--;
		}
	}
	return stepsRemaining;
}

/******************************************************************************
*							MapRoom1::printMap
* Prints map of the current Room. Includes legend and changes depending on the
* user's interactions with the spaces. Also prints step counter.
******************************************************************************/
void MapRoom1::printMap()
{
	cout << endl;

	cout << " ________________________________________ " << endl;
	cout << "|                 LEGEND                 |" << endl;
	cout << "|----------------------------------------|" << endl;
	cout << "|      L - Link's current position       |" << endl;
	cout << "| D - Door, Locked    d - Door, unlocked |" << endl;
	cout << "| T - Torch, lit      t - Torch, unlit   |" << endl;
	cout << "| m - Enemy, Mummy                       |" << endl;
	cout << "|________________________________________|" << endl;

	cout << endl;

	cout << "Here is the current map of Room 1:" << endl << endl;
	cout << "              _____" << endl;
	cout << "             |  " << A5.showDoor() << "  |" << endl;
	cout << "             |  " << A5.showLink() << "  |" << endl;
	cout << "             |_____|" << endl;
	cout << "             |     |" << endl;
	cout << "             |" << A4.showTorch() << " " << A4.showLink() << " " << A4.showTorch();
	cout << "|" << endl;
	cout << "             |_____|" << endl;
	cout << "             |  " << A3.showEnemy() << "  |" << endl;
	cout << "             |  " << A3.showLink() << "  |" << endl;
	cout << "             |_____|" << endl;
	cout << "             |     |" << endl;
	cout << "             |" << A2.showTorch() << " " << A2.showLink() << " " << A2.showTorch() << "|" << endl;
	cout << "             |_____|" << endl;
	cout << "             |     |" << endl;
	cout << "             |  " << A1.showLink() << "  |" << endl;
	cout << "             |__" << A1.showDoor() << "__|" << endl;
	
	cout << endl;
	cout << "Steps Remaining : " << stepsRemaining << endl << endl;
}
