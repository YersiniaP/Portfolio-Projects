/******************************************************************************
 * Program Name:	Final Project (reused from Final Project)
 * Author:			Sarah Leon
 * Date:			08/12/2019
 * Description:		Derived class for a Mummy fantasy character. Does not 
 *					contain any data members in addition to those in the base
 *					Character class. The default constructor intializes those
 *					data members. One class method is responsible for the 
 *					Mummy offensive and another for it's defensive actions
 *					each round of combat. These two methods override their
 *					virtual counterparts in the abstract base class.
 * ***************************************************************************/
#include "Character.h"

#ifndef MUMMY_HPP 
#define MUMMY_HPP

class Mummy :
	public Character
{
	private:
		//no additional data members
		//only uses ones from base class

	public:
		Mummy();				//default constructor

		int launchAttack();		//returns damage done by Mummy

		void defend(int);		//calculates amount of damage taken
};

#endif
