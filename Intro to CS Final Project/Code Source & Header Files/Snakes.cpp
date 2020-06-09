/******************************************************************************
* Program Name:		Final Project (reused from Project 3)
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Derived class for a Snakes fantasy character. The
*					default constructor intializes the data members. One class
*					method is responsible for the Snakes offensive and
*					another for it's defensive actions each round of combat.
*					These two methods override their virtual counterparts in
*					the abstract base class. The additonal mob() function is
*					responsible for the	class's	unique Mob passive ability.
******************************************************************************/
#include <iostream>
#include "Snakes.h"

using std::cout;
using std::endl;

/******************************************************************************
*							Snakes::Snakes
* Default constructor for Snakes character. Initialized armor and starting
* strenthPoint values. The isAlive bool is set to true, as the character is 
* alive at the start of the game. The number of dice used in dice rolls
* begins at 3.
******************************************************************************/
Snakes::Snakes()
{
	armor = 0;
	hearts = 12;

	numDice = 3;		//At full hearts, Snakes rolls 3 dice when defending

	isAlive = true;
}

/******************************************************************************
*							Snakes::launchAttack
* Function that determines the amount of damage dealt by the Snakes.The diceRoll
* function is called twice using 4-sided dice. The result is displayed and 
* also returned.
******************************************************************************/
int Snakes::launchAttack()
{
	int attackDamage = 0;

	for (int i = 0; i < numDice; i++)
	{
		attackDamage += diceRoll(4);		//rolls [numDice]d4 for attack
	}
	
	cout << "Snakes roll" << numDice << "d4 for attack and get: ";
	cout << attackDamage << endl;

	return attackDamage;
}

/******************************************************************************
*							Snakes::defend
* Function that determines the number of hearts lost by the Snakes after an
* attack. It takes an int parameter, the amount of damage the opponent deals in
* the attack. The diceRoll function is called numDice number of times using 
* 6-sided dice. This is added to the amount of armor the Snakes has, represent
* the total amount of defense/damage of the attack that is mitigated. The net 
* damage taken is deducted from the Snakes's hearts (stopping at 0) and all 
* calculations are displayed. If the hearts reach 0, the Snakes dies and the
* isAlive bool is set to false. The mob function is called, updating numDice 
* as needed.
******************************************************************************/
void Snakes::defend(int attackDamage)
{
	int defenseRolls = 0;

	numDice = mob();

	for (int i = 0; i < numDice; i++)
	{
		defenseRolls += diceRoll(6);		//rolls [numDice]d6 for defense
	}
	
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

	if (hearts > damageTaken)
	{
		hearts -= damageTaken;
	}
	else
	{
		hearts = 0;
		isAlive = false;
	}

	cout << "Snakes roll " << numDice << "d6 for Defense and get: ";
	cout << defenseRolls << endl;

	cout << "With " << armor << " armor, the total damage mitigated is ";
	cout << damageMitigated << endl;

	cout << "The " << attackDamage << " damage attack deals " << damageTaken;
	cout << " damage, and leaves the Snakes with ";
	cout << hearts << " hearts" << endl << endl;
}

/******************************************************************************
*							Snakes::mob
* Function that determines the number of dice used (numDice) when the attack or
* defend function is called. Every 4 hearts lost results in loss of one die.
******************************************************************************/
int Snakes::mob()
{
	if (hearts <= 4)
	{
		return 1;		//lost two dice, only one remains
	}
	else if (hearts > 4 && hearts <= 8)
	{
		return 2;		//lost a die, two remaining
	}
	else	//hearts > 8
	{
		return 3;		//still have 3 defense dice
	}
}
