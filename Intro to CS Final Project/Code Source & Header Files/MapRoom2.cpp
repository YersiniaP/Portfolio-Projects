/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Second room in the dungeon. Spaces (4): 2 DoorSpaces, and 2
* JarSpaces. Enemies: snakes. Items: key, redPotion. Constructor links
* and initializes variables. Includes a function to play rounds of travel/combat
* and print the map. A secret switch is under the B2 jar and triggers snakes.
******************************************************************************/
#include <iostream>
#include "MapRoom2.h"
#include "inputValid.hpp"

using std::cout;
using std::endl;

/******************************************************************************
*							MapRoom2::MapRoom2
* Contructor to link spaces and initialize variables. Places link in first space
* on map. Takes step counter as a parameter.
******************************************************************************/
MapRoom2::MapRoom2(int* steps)
{
	B1 = DoorSpace(&B2, nullptr, nullptr, &B4);
	B2 = JarSpace(nullptr, &B1, nullptr, &B3);
	B3 = DoorSpace(nullptr, &B4, &B2, nullptr);
	B4 = JarSpace(&B3, nullptr, &B1, nullptr);

	key = Item(4);			//creates key item
	potion = Item(1);		//creates redPotion item

	B1.toggleLink();		//Link's position on map

	stepsRemaining = *steps;
	roomFinished = false;
	switchTriggered = false;	//jar in place
}

/******************************************************************************
*							MapRoom2::navigateRoom2
* Allows player to traverse room with Space pointers. Player pointer moves along
* the Spaces while the character interacts with enemies/items. A menu prompts at
* the start of each space and the counter increased at the end. Door is only
* unlocked by triggering the secret switch, killing the snakes, and getting
* the key they drop.
******************************************************************************/
int MapRoom2::navigateRoom2(Space* linkPtr, Link *player)
{
	linkPtr = &B1;
	while (!roomFinished && stepsRemaining > 0)
	{
		printMap();

		linkPtr->describeSquare();
		if (linkPtr == &B1)  //options for the first space
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move up a square" << endl;
			cout << " 2) Move right a square" << endl;

			string choose = "Please enter 1 or 2: ";

			int choice = inputValid(choose, 1, 2);
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = B1.moveUp();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = B1.moveRight();
				linkPtr->toggleLink();
			}
			stepsRemaining--;
		}
		else if (linkPtr == &B2)	
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move right a square" << endl;
			cout << " 2) Move down a square" << endl;
			cout << " 3) Open the Jar" << endl;

			string choose = "Please enter 1, 2, or 3";

			int choice = inputValid(choose, 1, 3);
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = B2.moveRight();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = B2.moveDown();
				linkPtr->toggleLink();
			}
			else  //choice == 3
			{
				linkPtr->interactSpace();  // picks up Jar
				cout << "Picking up the jar trips secret switch!" << endl;
				switchTriggered = true;

				cout << "Snakes fall the ceiling and attack you!";

				cout << "Link fights snakes" << endl;
				while (snakes.getStatus())			//same as combat in Room 1
				{
					snakes.defend(player->launchAttack());
					if (snakes.getStatus())
					{
						player->defend(snakes.launchAttack());
					}
					if (!player->getStatus())
					{
						cout << "You've died!" << endl;
						stepsRemaining = 0;
						return stepsRemaining;
					}
				}
				cout << "There is something glinting in the pile of defeated snakes" << endl;
				player->printBelt();
				player->addItem(key); //key added to Link's Utility Belt
				player->printBelt();
				cout << "You've added a key to your Utility Belt" << endl;
			}
			stepsRemaining--;
		}
		else if (linkPtr == &B3) //options in third square
		{
			cout << "What would you like to do?" << endl;

			cout << " 1) Move left a square" << endl;
			cout << " 2) Move down a square" << endl;
			cout << " 3) Try the door" << endl;

			string choose = "Please enter 1, 2, or 3: ";
			int choice = inputValid(choose, 1, 3);
			
			if (choice == 1)
			{
				linkPtr->toggleLink();
				linkPtr = B3.moveLeft();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = B3.moveDown();
				linkPtr->toggleLink();
			}
			else if (choice == 3)
			{
				if (player->hasKey())  //key is consumed upon opening door
				{
					cout << "You unlock the door with your key and enter the next room" << endl;
					roomFinished = true;
					player->printBelt();
				}
				else //need to trigger the secret switch to get the key
				{
					cout << "The door is locked but you notice it has a keyhole." << endl;
				}
			}
			stepsRemaining--;
		}
		else if (linkPtr == &B4)  //options in square 4
		{
			int choice = 0;
			cout << "What would you like to do?" << endl;

			cout << " 1) Move left a square" << endl;
			cout << " 2) Move up a square" << endl;

			if (!B4.jarStatus())  //no snakes here
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
				linkPtr = B4.moveLeft();
				linkPtr->toggleLink();
			}
			else if (choice == 2)
			{
				linkPtr->toggleLink();
				linkPtr = B4.moveUp();
				linkPtr->toggleLink();
			}
			else if (choice == 3) //redPotion added to Link's Utility Belt
			{
				linkPtr->interactSpace();
				cout << "You find a Red Potion and add it to your inventory!" << endl;
				player->addItem(potion);
			}
			stepsRemaining--;
		}
	}
	return stepsRemaining;
}


/******************************************************************************
*							MapRoom2::printMap
* Prints map of the current Room. Includes legend and changes depending on the
* user's interactions with the spaces. Also prints step counter.
******************************************************************************/
void MapRoom2::printMap()
{
	cout << endl;
	cout << " ________________________________________ " << endl;
	cout << "|                 LEGEND                 |" << endl;
	cout << "|----------------------------------------|" << endl;
	cout << "|      L - link's current position       |" << endl;
	cout << "| D - Door, Locked    d - Door, unlocked |" << endl;
	cout << "| J - Jar, Unopened   j - Jar, opened    |" << endl;
	if (switchTriggered)
	{
		cout << "| o - Secret Switch                       " << endl;
	}
	cout << "|________________________________________|" << endl;

	cout << endl << endl;


	cout << "Here is the current map of Room 2:" << endl << endl;

	cout << "              ___________" << endl;
	cout << "             |" << B2.showJar(switchTriggered)<< "    |     |" << endl;
	cout << "             |  " << B2.showLink() << "  | " << B3.showLink();
	cout << "  " << B3.showDoor() << "| " << endl;
	cout << "             |_____|_____|" << endl;
	cout << "             |     |     |" << endl;
	cout << "             |  " << B1.showLink() << "  |  " << B4.showLink() << "  |" << endl;
	cout << "             |__" << B1.showDoor() << "__|____" << B4.showJar() << "|" << endl << endl;

	cout << "Steps Remaining : " << stepsRemaining << endl << endl;
}
