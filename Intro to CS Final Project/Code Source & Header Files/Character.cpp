/******************************************************************************
* Program Name:	Final Project (reused from Project 3)
* Author:			Sarah Leon
* Date:			08/12/2019
* Description:		Abstract class for a given fantasy character. Contains four
*					int data members representing player stats, and a fifth
*					flags the character as dead or alive. The default constructor
*					exists soley for derived class use. The first two methods
*					are pure virual functions, and are not defined here, while
*					the third is a getter for the isAlive data member.
******************************************************************************/
#include "Character.h"

/******************************************************************************
*					Character::Character
* Default constructor for character class. Exists soley for the derived classes
* to use during their instantiation.
******************************************************************************/
Character::Character()
{
	armor = 0;				
	hearts = 0;

	isAlive = true; 
}

/******************************************************************************
*					Character::getStatus
* Determines if the given Character is alive or not by returning the isAlive
* bool data member.
******************************************************************************/
bool Character::getStatus()
{
	return isAlive;
}
