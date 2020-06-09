/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Final room in the dungeon. This is room is a sigle "space"
but it not actually derived from the Space class. It's a fun bonus room of sorts
to battle the final boss. Enemies: Mothula. Items: none. Includes a function to
play rounds of combat and print the map. If the player chose a bee at the start,
it will aid Link in battle.
******************************************************************************/
#include <iostream>
#include "Space.h"
#include "Link.h"
#include "BossRoom.h"

using std::cout;
using std::endl;

/******************************************************************************
*							BossRoom::BossFight
* Function for Link to battle Mothula. After some fantasy text, Link attacks
* Mothula. If she survives she will attack back. If the player has a bee, it 
* will damage Mothula (but cannot deliver a killing blow). Death of either 
* character ends the game.
******************************************************************************/
void BossRoom::bossFight(Space* linkPtr, Link* player)
{
	cout << "You fall a long way before landing with a gentle -poof!-" << endl;
	cout << "Something large and soft has broken your fall." << endl;
	cout << "To your horror, you realize it a moth as large as the room." << endl;
	cout << endl;

	if (player->hasBee() == true)
	{
		cout << "You hear a light -tink- -tink- -tink- sound" << endl;
		cout << "Looking down, you realize your bee is enraged by the sight";
		cout << "of Mothula!"<< endl << endl;
		cout << "You wearily uncork the bottle and hope for the best." << endl << endl;
	}

	while (mothula.getStatus() && player->getStatus()) //if both characters are alive
	{
		printMap();

		mothula.defend(player->launchAttack()); //Link attacks first
		if (mothula.getStatus())	//If she survives hit,
		{
			player->defend(mothula.launchAttack()); //Mothula attacks
		}

		if (player->hasBee())		//if player chose Bee
		{
			mothula.unBEElievable();		//bit damages Mothula
		}
		if (!player->getStatus())	//exits if player dies
		{
			cout << "You've died!"  << endl;
			return;
		}
	}
}

/******************************************************************************
*							BossRoom::printMap
* Map of Mothula's Boss Room. Although the player doesn't move and the map does
* not change, it is shown to intimidate the user. :)
******************************************************************************/
void BossRoom::printMap()
{
	cout << "Here is the current Map "  << endl;

	cout << "              _________________" << endl;
	cout << "              |XXXXXXXXXXXXXXX|" << endl;
	cout << "              |X  __ ]_[ __  X|" << endl;
	cout << "              |X (||\\(\")/||) X|" << endl;
	cout << "              |X  )<{{~}}>(  X|"   << endl;
	cout << "              |X (||/{~}\\||) X|" << endl;
	cout << "              |X             X|" << endl;
	cout << "              |X      L      X|"     << endl;
	cout << "              |XXXXXXXXXXXXXXX|" << endl << endl;
}
