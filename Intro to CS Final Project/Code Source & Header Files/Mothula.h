/******************************************************************************
 * Program Name:	Final Project (reused from Project 3)
 * Author:			Sarah Leon
 * Date:			07/25/2019
 * Description:		Derived class for a Mothula fantasy character. Does not 
 *					contain any data members in addition to those in the base
 *					Character class. The default constructor intializes those
 *					data members. One class method is responsible for the 
 *					Mothula offensive and another for it's defensive actions
 *					each round of combat. These two methods override their
 *					virtual counterparts in the abstract base class. The third
 *					is special condition in case Link has a bee.
 * ***************************************************************************/
#include "Character.h"

#ifndef MOTHULA_HPP 
#define MOTHULA_HPP

class Mothula :
	public Character
{
	private:


	public:
		Mothula();				//default constructor

		int launchAttack();		//returns damage done by Mothula

		void defend(int);		//calculates amount of damage taken

		void unBEElievable();  //special condition if Link has a bee
};
#endif