/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Main funtion that controls the flow of the game. Creates
*					player character, pointer the traverse rooms, the rooms 
* themselves, and the intial game setup menus. A step counter will prematurely
* end the game if it reaches zero (or if Link dies).
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Space.h"
#include "Link.h"
#include "MapRoom1.h"
#include "MapRoom2.h"
#include "MapRoom3.h"
#include "BossRoom.h"
#include "Container.h"
#include "menuFinal.h"
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));		//seeded for diceRoll function

	int introChoice = menuIntro();	//displays intro menu
	while (introChoice != 3)
	{
		if (introChoice == 1)
		{
			textBackstory();	//optional
		}
		else if (introChoice == 2)
		{
			textCombat();		//optional
		}

		introChoice = menuIntro();
	}
	
	cout << endl << " * * * * * * * START GAME * * * * * * * * " << endl << endl;


	int stepsRemaining = 30;			//timer

	Space *linkPtr = nullptr;			//pointer that will travel/interact spaces

	Link link;							//character that will fight enemies/use items

	Link *playerLink = &link;			//character pointer

	int bottleChoice = startBottles();		//choose which bottle to start with

	Item startingItem(bottleChoice);		

	link.addItem(startingItem);				//added to Link's Utility Belt

	MapRoom1 Room1(&stepsRemaining);		//create first room

	stepsRemaining = Room1.navigateRoom1(linkPtr, playerLink);	//Link explores first room

	//subsequent rooms are explored if Link is alive and steps remain
	if (stepsRemaining > 0)  
	{
		MapRoom2 Room2(&stepsRemaining);

		stepsRemaining = Room2.navigateRoom2(linkPtr, playerLink);
	}
	if (stepsRemaining > 0)
	{
		MapRoom3 Room3(&stepsRemaining);

		stepsRemaining = Room3.navigateRoom3(linkPtr, playerLink);
	}
	if (stepsRemaining > 0)
	{
		BossRoom Room4;

		Room4.bossFight(linkPtr, playerLink);
	}

	if (stepsRemaining == 0)
	{
		cout << "You ran out of steps" << endl;
	}
	else
	{
		cout << "Congratulations! You've saved one of the seven sages!" << endl;
	}
	return 0;
}