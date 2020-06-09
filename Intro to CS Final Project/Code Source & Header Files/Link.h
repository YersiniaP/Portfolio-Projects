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
#include "Character.h"
#include "Container.h"

#ifndef LINK_HPP
#define LINK_HPP

class Link :
	public Character
{
	private:

		Container utilityBelt;

	public:
		Link();					//initializes data members

		int launchAttack();		//return damage done by Link

		void defend(int);		//calculates amount of damage taken

		void useFairy();		//uses fairy if available

		bool hasKey();			//Utility Belt contains key

		bool hasBee();

		bool hasFairy();

		void addItem(Item);		//add item to Utility Belt

		void useRedPoition();

		void printBelt();		//print belt
};
#endif