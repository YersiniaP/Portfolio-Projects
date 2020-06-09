/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/07/2019
* Decription:		Menu functions for the Final Project. A menu is displayed 
* before each action the user can take. All entries verified with inputValid().
******************************************************************************/
#include <iostream>
#include "menuFinal.h"
#include "inputValid.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/****************************************************************************
*					menuIntro
* Displayed at the beginning of the program, allowing to choose to read story
* and gameplay information (or just start the game).
******************************************************************************/
int menuIntro()
{
	cout << "What would you like to do?" << endl << endl;

	cout << " 1) Read backstory" << endl;
	cout << " 2) Read combat rules and item details" << endl;
	cout << " 3) Start game" << endl;

	string choose = "Please enter an integer between 1 and 3: ";

	return inputValid(choose, 1, 3);		//returns validated entry
}

/****************************************************************************
*					textBackstory
* Information about the program and character's backstory.
******************************************************************************/
void textBackstory()
{
	cout << endl;
	cout << "The theme of this program is a recreation of a small part of" << endl;
	cout << "the video game, The Legend of Zelda : A Link to the Past (for SNES)." << endl;
	cout << "Specifically, you will be exploring the last few rooms of the" << endl;
	cout << "Skull Woods dungeon, facing its Boss, Mothula, and rescuing one of" << endl;
	cout << "the seven sages." << endl << endl;

	cout << "You are the brave adventurer named Link. To reach the end of the dungeon," << endl;
	cout << "Link will have to solve puzzles and defeat the enemies in his way. He has a" << endl;
	cout << "few weapons and items in his possession to help him in any way possible." << endl;
}

/****************************************************************************
*					textCombat
* Information about the program's combat and item rules.
******************************************************************************/
void textCombat()
{
	cout << endl;
	cout << "The combat of this program is identical to the Fantasy Combat project. Dice are rolled" << endl;
	cout << "to determine attack and defence damage score. Entering a square with an enemy" << endl;
	cout << "will automatically trigger combat, and will only end when someone dies." << endl;
	cout << endl;
	cout << "Link can hold up to three items in his Utility Belt. Some of these are used" << endl;
	cout << "automatically in certain conditions, while others can be used by a menu option" << endl;
}

/****************************************************************************
*					startBottles
* Allows user to choose which bottle to play the game with.
******************************************************************************/
int startBottles()
{
	cout << "On your way to the dungeon Link trips in the woods, splits his backpack," << endl;
	cout << "and is only able to carry what can be attached to his belt. To be safe," << endl;
	cout << "you'll only take one of your bottles with you, to leave room for future items." << endl;
	cout << endl << "Which bottle would you like to take?" << endl << endl;

	cout << " 1) Red Potion - Restores 10 hearts " << endl;
	cout << " 2) Fairy - Upon death, Link returns to life once with full hearts" << endl;
	cout << " 3) Bee - It's just a bee" << endl;

	string choose = "Please enter an integer between 1 and 3: ";

	return inputValid(choose, 1, 3);		//returns validated entry
}

/****************************************************************************
*					chooseAttack
* Displayed before each round of combat. Allows user to choose how Link attacks.
******************************************************************************/
int chooseAttack()
{
	cout << "How you would you like to attack?" << endl;

	cout << " 1) Swing Master Sword" << endl;
	cout << " 2) Use the Fire Rod" << endl;
	cout << " 3) Use Mallet" << endl;

	string choose = "Please enter 1, 2, or 3";

	return inputValid(choose, 1, 3);
}