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
#include <iostream>
#include "Mothula.h"

using std::cout;
using std::endl;

/******************************************************************************
*							Mothula::Mothula
* Default constructor for Mothula character. Initialized armor and starting
* strenthPoint values. The isAlive bool is also set to true, as the character
* is alive at the start of the game.
******************************************************************************/
Mothula::Mothula()
{
	armor = 0;
	hearts = 20;

	isAlive = true;
}

/******************************************************************************
*							Mothula::launchAttack
* Function that determines the amount of damage dealt by the Mothula. She will
* randomly choose which attack type to use. The diceRoll function is then called
* the appropriate number of times. The result is displayed and also returned.
******************************************************************************/
int Mothula::launchAttack()
{
	int attackType = diceRoll(2);
	int attackDamage = 0;

	if (attackType == 1)
	{
		cout << "Mothula wing clips Link!" << endl;
		cout << "Mothula rolls 2d6 for attack and gets: ";
		attackDamage = diceRoll(8) + diceRoll(8); //rolls 2d6
	}
	else
	{
		cout << "Mothula screeches loudly!" << endl;
		cout << "Mothula rolls 4d4 for attack and gets: ";
		attackDamage = diceRoll(4) + diceRoll(4) + diceRoll(4); //rolls 3d4
	}
	   	
	cout << attackDamage << endl;

	return attackDamage;		//return damage to calling function
}

/******************************************************************************
*							Mothula::defend
* Function that determines the number of hearts lost by the Mothula after an 
* attack. It takes an int parameter, the amount of damage the opponent deals in
* the attack. The diceRoll function is called twice using 8-sided dice and 
* result is displayed. This is added to the amount of armor the Mothula has, 
* representing the total amount of defense/damage of the attack that is mitigated.
* The net damage taken is deducted from the Mothula's hearts (stopping at 0) 
* and all calculations are displayed. If the hearts reach 0, the Mothula dies
* and the isAlive bool is set to false.
******************************************************************************/
void Mothula::defend(int attackDamage)
{
	int defenseRolls = diceRoll(8) + diceRoll(8);		//rolls 2d8 for defense
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
	else	//otherwise, the Mothula dies
	{
		hearts = 0;		//hearts can go no lower than 0
		isAlive = false;		//no longer alive
	}
	

	cout << "Mothula rolls 2d6 for Defense and gets: ";
	cout << defenseRolls << endl;

	cout << "With " << armor << " armor, the total damage mitigated is ";
	cout << damageMitigated << endl;

	cout << "The " << attackDamage << " damage attack deals " << damageTaken;
	cout << " damage, and leaves Mothula with ";
	cout << hearts << " hearts" << endl << endl;
}

/******************************************************************************
*							Mothula::unBEELievable
* Function called if Link has a bee. The bee causes Mothula to lose one heart
* each turn (but cannot be killed this way).
******************************************************************************/
void Mothula::unBEElievable()
{
	if (hearts > 2)
	{
		cout << "The bee deals 1 damage to Mothula" << endl;
		hearts--;

		cout << "Mothula has " << hearts << "remaining" << endl;
	}
}