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
#include "MapRoom3.h"
#include <iostream>
#include "inputValid.hpp"

using std::cout;
using std::endl;

/******************************************************************************
*							MapRoom2::MapRoom2
* Contructor to link spaces and initialize variables. Places link in first space
* on map. Takes step counter as a parameter.
******************************************************************************/
MapRoom3::MapRoom3(int *steps)
{
	C1 = EnemySpace(&C2, nullptr, nullptr, &C4);
	C2 = DoorSpace(nullptr, &C1, nullptr, &C3);
	C3 = HoleSpace(nullptr, &C4, &C2, nullptr);
	C4 = JarSpace(&C3, nullptr, &C1, nullptr);

	potion = Item(1);  //creates redPotion item

	C2.toggleLink();  //map shows Link in second square

	stepsRemaining = *steps;
	roomFinished = false;
}

/******************************************************************************
*							MapRoom3::navigateRoom3
* Allows player to traverse room with Space pointers. Player pointer moves along
* the Spaces while the character interacts with enemies/items. A menu prompts at
* the start of each space and the counter increased at the end. Jumping into the
* hole actually is the way to the final boss.
******************************************************************************/
int MapRoom3::navigateRoom3(Space* linkPtr, Link* player)
{
	linkPtr = &C2; //Link starts in the second space
	while (!roomFinished && stepsRemaining > 0)
	{
		printMap();

		linkPtr->describeSquare();
		if (linkPtr == &C1)	//Options in first square
		{
			if (C1.getEnemyStatus())
			{
				cout << "Link fights mummy" << endl;
				while (mummy.getStatus() && player->getStatus())
				{
					mummy.defend(player->launchAttack());
					if (mummy.getStatus())
					{
						player->defend(mummy.launchAttack());
					}
					if (!player->getStatus())
					{
						cout << "You've died!" << endl;
						stepsRemaining = 0;
						return stepsRemaining;
					}
				}
				C1.setEnemyStatus(false);
			}
			cout << "What would you like to do?" << endl;

			cout << " 1) Move up a square" << endl;
			cout << " 2) Move right a square" << endl;

			string choose = "Please enter 1 or 2: ";

			int choice = inputValid(choose, 1, 2);
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = C1.moveUp();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = C1.moveRight();
				linkPtr->toggleLink();
			}
			stepsRemaining--;
		}
		else if (linkPtr == &C2)  //options in square 2
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move right a square" << endl;
			cout << " 2) Move down a square" << endl;

			string choose = "Please enter 1, or 2";

			int choice = inputValid(choose, 1, 2);
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = C2.moveRight();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = C2.moveDown();
				linkPtr->toggleLink();
			}
			stepsRemaining--;
		}
		else if (linkPtr == &C3) //options for square 3
		{
			cout << "What would you like to do?" << endl;

			int choice = 0;

			cout << " 1) Move left a square" << endl;
			cout << " 2) Move down a square" << endl;
			cout << " 3) Jump in the Hole" << endl;  //YES!

			string choose = "Please enter 1, 2, or 3: ";
			choice = inputValid(choose, 1, 3);
			
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = C3.moveLeft();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = C3.moveDown();
				linkPtr->toggleLink();
			}
			else if (choice == 3) //takes Link to room below
			{
				linkPtr->interactSpace();
				roomFinished = true;
			}
			stepsRemaining--;
		}
		else if (linkPtr == &C4) //options for square 4
		{
			int choice = 0;
			cout << "What would you like to do?" << endl;

			cout << " 1) Move left a square" << endl;
			cout << " 2) Move up a square" << endl;

			if (!C4.jarStatus())
			{
				cout << " 3) Open the Jar" << endl;

				string choose = "Please enter 1, 2, or 3";

				choice = inputValid(choose, 1, 3);
			}
			else
			{
				string choose = "Please enter 1 or 2";
				choice = inputValid(choose, 1, 2);
			}
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = C4.moveLeft();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = C4.moveUp();
				linkPtr->toggleLink();
			}
			else if (choice == 3)
			{
				linkPtr->interactSpace();
				cout << "You find a Red Potion and add it to your inventory!" << endl;
				player->addItem(potion);
			}
		}
		stepsRemaining--;
	}
	return stepsRemaining;
}

/******************************************************************************
*							MapRoom3::printMap
* Prints map of the current Room. Includes legend and changes depending on the
* user's interactions with the spaces. Also prints step counter.
******************************************************************************/
void MapRoom3::printMap()
{
	cout << endl;

	cout << " ________________________________________ " << endl;
	cout << "|                 LEGEND                 |" << endl;
	cout << "|----------------------------------------|" << endl;
	cout << "|      L - Link's current position       |" << endl;
	cout << "| D - Door, Locked    d - Door, unlocked |" << endl;
	cout << "| J - Jar, Unopened   j - Jar, opened    |" << endl;
	cout << "| # - Hole in Floor                      |" << endl;
	cout << "|________________________________________|" << endl;
	cout << endl;

	cout << "Here is the current map of Room 2:" << endl << endl;

	cout << "              ___________" << endl;
	cout << "             |     |   ##|" << endl;
	cout << "             |" << C2.showDoor() << " " << C2.showLink() << "  | ";
	cout << C3.showLink() << "###|" << endl;
	cout << "             |_____|_____|" << endl;
	cout << "             |     |     |" << endl;
	cout << "             |  " << C1.showLink() << "  |  " << C4.showLink() << "  |" << endl;
	cout << "             |__" << C1.showEnemy() << "__|____" << C4.showJar() << "|" << endl;

	cout << endl;

	cout << "Steps Remaining : " << stepsRemaining << endl << endl;
}
