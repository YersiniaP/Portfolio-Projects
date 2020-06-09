/****************************************************************************
* Program Name:	Final Project (reused from Project 3)
* Author:			Sarah Leon
* Date:			08/12/2019
* Description:		Function to emulate a the roll of a die. Passed integer
*					represents the number of sides on the die. The rand
*					function is seeded in the main function with the user's 
*					clock. Returns a number between 1 and the passed integer.
******************************************************************************/

#include <cstdlib>
#include "diceRoll.h"

int diceRoll(int numSides)
{
	return rand() % numSides + 1;  
}
