/******************************************************************************
* Program Name:		Final Project (reused from Project 3)
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Derived class for a Mummy fantasy character. The default
*					constructor intializes the data members. One class method is
*					responsible for the	Mummy offensive and another for it's
*					defensive actions each round of combat. These two methods
*					override their virtual counterparts in the abstract base 
*					class.
* ***************************************************************************/
#include <iostream>
#include "Mummy.h"

using std::cout;
using std::endl;

/******************************************************************************
*							Mummy::Mummy
* Default constructor for Mummy character. Initialized armor and starting
* strenthPoint values. The isAlive bool is also set to true, as the character
* is alive at the start of the game.
******************************************************************************/
Mummy::Mummy()
{
	armor = 0;
	hearts = 8;

	isAlive = true;
}

/******************************************************************************
*							Mummy::launchAttack
* Function that determines the amount of damage dealt by the Mummy. The diceRoll
* function is called twice using 6-sided dice. The result is displayed and returned.
******************************************************************************/
int Mummy::launchAttack()
{
	int attackDamage = diceRoll(6) + diceRoll(6); //rolls 2d6

	cout << "Mummy rolls 2d6 for attack and gets: ";
	cout << attackDamage << endl;

	return attackDamage;		//return damage to calling function
}

/******************************************************************************
*							Mummy::defend
* Function that determines the number of hearts lost by the Mummy after an 
* attack. It takes an int parameter, the amount of damage the opponent deals in
* the attack. The diceRoll function is called twice using 6-sided dice and result
* is displayed. This is added to the amount of armor the Mummy has, represent 
* the total amount of defense/damage of the attack that is mitigated. The net
* damage taken is deducted from the Mummy's hearts (stopping at 0) and all
* calculations are displayed. If the hearts reach 0, the Mummy dies and the 
* isAlive bool is set to false.
******************************************************************************/
void Mummy::defend(int attackDamage)
{
	int defenseRolls = diceRoll(6);		//rolls 1d6 for defense
	int damageMitigated = defenseRolls + armor;			//added to armor for total defense score

	int damageTaken;		//damage taken after defending damage

	if (damageMitigated > attackDamage)		
	{
		damageTaken = 0;		//no damage taken if defense is high enough
	}
	else		//otherwise only some of the attack damage is mitigated
	{
		damageTaken = attackDamage - damageMitigated;	
	}
	
	if (hearts > damageTaken)		//if it isn't a killing blow
	{
		hearts -= damageTaken;		//update hearts
	}
	else	//otherwise, the Mummy dies
	{
		hearts = 0;		//hearts can go no lower than 0
		isAlive = false;		//no longer alive
	}
	
	cout << "Mummy rolls 2d6 for Defense and gets: ";
	cout << defenseRolls << endl;

	cout << "With " << armor << " armor, the total damage mitigated is ";
	cout << damageMitigated << endl;

	cout << "The " << attackDamage << " damage attack deals " << damageTaken;
	cout << " damage, and leaves Mummy with ";
	cout << hearts << " hearts" << endl << endl;
}
