/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Final room in the dungeon. This is room is a sigle "space"
but it not actually derived from the Space class. It's a fun bonus room of sorts
to battle the final boss. Enemies: Mothula. Items: none. Includes a function to
play rounds of combat and print the map.
******************************************************************************/
#include "Mothula.h"

#ifndef BOSSROOM_HPP
#define BOSSROOM_HPP

class BossRoom
{
private:
	Mothula mothula;			//enemy

public:
	//nothing to initialize in a constructor

	void bossFight(Space*, Link*);  //only actions in this room the boss fight

	void printMap();	
};
#endif 