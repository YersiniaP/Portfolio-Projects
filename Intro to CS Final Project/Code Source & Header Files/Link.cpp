/******************************************************************************
* Program Name:		Final Project (reused from Final Project)
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Derived class for a Link fantasy character. In addition
*					to the data members in the base, there is a Container to hold
* the items Link finds. The default constructor intializes these data members.
* One class method is responsible for the Link offensive and another for his
* defensive actions	each round of combat. The three 'has' functions check the
* Container for specific items and there is a function to add to it. Two functions
* allow use of these items and the last prints the contents of the container.
******************************************************************************/
#include <iostream>
#include "menuFinal.h"
#include "Link.h"

using std::cout;
using std::endl;

/******************************************************************************
*							Link::Link
* Default constructor for Link character. Initialized armor and starting
* strenthPoint values. The isAlive bool is set to true, as the character is 
* alive  at the start of the game.
******************************************************************************/
Link::Link()
{
	armor = 5;		//Link is only character in game to have armor/a shield

	hearts = 20;
	isAlive = true;
}

/******************************************************************************
*							Link::launchAttack
* Function that determines the amount of damage dealt by the Link. The diceRoll
* function is called for the user-selected attack type, using appropriate dice.
* The result is displayed and also returned.
******************************************************************************/
int Link::launchAttack()
{
	int attackChoice = chooseAttack();

	int attackDamage = 0;
	
	if (attackChoice == 1)
	{
		attackDamage = diceRoll(8) + diceRoll(8);		//rolls 2d6
		cout << "Link rolls 2d8 for attack and gets: ";
	}
	else if (attackChoice == 2)
	{
		attackDamage = diceRoll(20);
		cout << "Link rolls 1d20 for attack and gets: ";
	}
	else
	{
		attackDamage = diceRoll(4) + diceRoll(4) + diceRoll(4);
		cout << "Link rolls 3d4 for attack and gets: ";
	}
	
	cout << attackDamage << endl;

	return attackDamage;							//damage dealt to opponent
}

/******************************************************************************
*							Link::defend
* Function that determines the number of hearts lost by the Link after an
* attack. It takes an int parameter, the amount of damage the opponent deals in
* the attack. The diceRoll function is called once using 10-sided dice and the
* result is displayed. This is added to the amount of armor the Link
* has, represent the total amount of defense/damage of the attack that is
* mitigated. The net damage taken is deducted from the Link's hearts (stopping at
* 0) and all calculations are displayed. Upon reaching 10 or fewer hearts, Link
* will use a redPotion if he has one (consumed on use). If the hearts reach 0, 
* then Link dies and the isAlive bool is set to false. The useFairy function 
* checks to see if Link has a Fairy to use, and return to life.
******************************************************************************/
void Link::defend(int attackDamage)
{
	int defenseRolls = diceRoll(10);		//rolls 1d10 for defense
	int damageMitigated = defenseRolls + armor;			//added to armor for total defense score

	int damageTaken;					//damage taken after defending damage

	if (damageMitigated > attackDamage)
	{
		damageTaken = 0;			//no damage taken if defense is high enough
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

	cout << "Link rolls 2d6 for Defense and gets: ";
	cout << defenseRolls << endl;

	cout << "With " << armor << " armor, the total damage mitigated is ";
	cout << damageMitigated << endl;

	cout << "The " << attackDamage << " damage attack deals " << damageTaken;
	cout << " damage, and leaves Link with ";
	cout << hearts << " hearts" << endl;

	useFairy();  //checks if a fairy can/should be used
	useRedPoition();  //checks if a redPotion can/should be used
	cout << endl;
}

/******************************************************************************
*							Link::useFairy
* Void function that determines if the Link's Fairy ability activates.
* If Link is reduced to 0 hearts and has not yet used his Fairy then Link returns
* to life. Upon coming back, isAlive is reverted to true, his hearts are set to 
* 20 and the fairy removed from the Utility Belt.
******************************************************************************/
void Link::useFairy()
{
	if (utilityBelt.hasTheFairy() && hearts == 0)
	{
		printBelt();
		cout << "Link's Fairy flies out of her bottle." << endl;
		cout << "He returns to life with 20 hearts!" << endl;

		hearts = 20;
		isAlive = true;						//return to life

		printBelt();
	}
}

bool Link::hasKey()
{
	return utilityBelt.hasTheKey();	
}

bool Link::hasBee()
{
	return utilityBelt.hasTheBee();
}

bool Link::hasFairy()
{
	return utilityBelt.hasTheFairy();
}

/******************************************************************************
*							Link::addItem
* Calls the Container's function to add an item to the Utility Belt.
******************************************************************************/
void Link::addItem(Item newItem)
{
	utilityBelt.addItem(newItem);
	cout << "Item added" << endl;
}

/******************************************************************************
*							Link::useRedPotion
* Looks for redPotion in belt and uses it to restore 10 hearts.
******************************************************************************/
void Link::useRedPoition()
{
	if (hearts < 11 && isAlive == true && utilityBelt.hasRedPotion())
	{
		cout << "You're losing a lot of hearts, so you drink the red potion." << endl;
		hearts += 10;
		cout << "Now you have " << hearts << " hearts." << endl;
		utilityBelt.printContainer();
	}
}

/******************************************************************************
*							Link::printBelt
* Calls the Container's print function.
******************************************************************************/
void Link::printBelt()
{
	utilityBelt.printContainer();
}
