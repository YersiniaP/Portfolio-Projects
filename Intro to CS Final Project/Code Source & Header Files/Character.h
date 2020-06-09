/******************************************************************************
* Program Name:		Final Project (reused from Project 3)
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Abstract class for a given fantasy character. Contains two
*					int data members representing player stats, and a third
*					flags the character as dead or alive. The default constructor
*					exists soley for derived class use. The first two methods
*					are pure virual functions, and allow derived classes to
*					easily override them, while the third is a getter for the
*					isAlive data member.
******************************************************************************/
#include "diceRoll.h"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int armor;				//character's base/constant defense again damage
		int hearts;				//total amount of damage the character can take
								//before dying (internally abbreviated as hearts)

		bool isAlive;			//true if hearts > 0

	public:
		Character();						//default Constructor

		virtual int launchAttack() = 0;		//Pure Virtual Functions designate
		virtual void defend(int) = 0;		//Character Class as Abstract

		bool getStatus();						//getter for isAlive
};

#endif