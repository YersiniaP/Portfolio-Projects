/******************************************************************************
 * Program Name:	Final Project (reused from Project 3)
 * Author:			Sarah Leon
 * Date:			08/12/2019
 * Description:		Derived class for a Snakes fantasy character. In addition
*					to those in the base Character class, the numDice
*					data member reprsents the number of dice used inside the
*			attack and defend functions. The default constructor intializes those
 *					data members. One class method is responsible for the
 *					Snakes offensive and another for it's defensive actions
 *					each round of combat. These two methods override their
 *					virtual counterparts in the abstract base class. The
 *					additonal mob() function is responsible for the class's
 *					unique mob ability, and alters the numDice variable.
 * ***************************************************************************/
#include "Character.h"

#ifndef SNAKES_HPP
#define SNAKES_HPP

class Snakes :
	public Character
{
	private:
		int numDice;			//number of dice rolled in combat

	public:
		Snakes();					//default constructor

		int launchAttack();		//return damage done by Mummy

		void defend(int);		//calculates amount of damage taken

		int mob();				//removes defense dice when enough damage taken
};

#endif