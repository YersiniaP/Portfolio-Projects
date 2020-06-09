/******************************************************************************
* Program Name:		Final Project 
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Class to hold Item objects. The constructor initialized the
*					array with empty items and another function can be used to 
* add Items to an empty slot. There is a function to print the contents of the
* array. The remaining functions are getters for the Items.
******************************************************************************/
#include <iostream>
#include "menuFinal.h"
#include "Container.h"

using std::cout;
using std::endl;

/******************************************************************************
*							Container::Container
* Initializes the array with empty items.
******************************************************************************/
Container::Container()
{
	for (int i = 0; i < 3; i++)
	{
		itemArray[i] = nonItem;
	}
}

/******************************************************************************
*							Container::printContainer
* Prints the contents of the container.
******************************************************************************/
void Container::printContainer()
{
	cout << "                   UTILITY BELT             " << endl;
	cout << "    ___________________________________________" << endl;
	cout << "   |___________________________________________|" << endl;
	cout << "   +++|++++|+++||-----|-----|-----||+++|++++|+++" << endl;
	cout << "   +++|++++|+++||";

	for (int i = 0; i < 3; i++)
	{
		cout << " ";
		if (itemArray[i].itemIsFake()) //empty space if a non item
		{
			cout << "   ";
		}
		else
		{
			itemArray[i].printItem();	//otherwise item's print function called
		}
		cout << " |";
	}
	cout << "|+++|++++|+++ " << endl;
	cout << "   +++|++++|+++||-----|-----|-----||+++|++++|+++" << endl;
	cout << "   |___________________________________________|" << endl << endl;
}

/******************************************************************************
*							Container::addItem
* Adds an item to the container. Looks for an empty item, and replaces it with 
* the passed parameter.
******************************************************************************/
void Container::addItem(Item newItem)
{
	bool itemInBelt = false;
	int i = 0;
	while(!itemInBelt)
	{
		if (itemArray[i].itemIsFake())  //item is empty
		{
			itemArray[i] = newItem;		//replaces with new item
			itemInBelt = true;
		}
		i++;
	}
	cout << "Your updated belt:" << endl << endl;
	printContainer();
}

/******************************************************************************
*							Container::hasRedPotion
* Getter for redPotion. Uses it when found.
******************************************************************************/
bool Container::hasRedPotion()
{
	bool gotRed = false;

	for (int i = 0; i < 3; i++)
	{
		if (!itemArray [i].itemIsFake() && itemArray[i].itemIsRed() && gotRed == false)
		{
			gotRed = true;
			itemArray[i] = nonItem;
		}
	}
	return gotRed;
}

/******************************************************************************
*							Container::hasTheKey
* Getter for key. Uses it when found.
******************************************************************************/
bool Container::hasTheKey()
{
	bool gotKey = false;

	for (int i = 0; i < 3; i++)
	{
		if (!itemArray[i].itemIsFake() && itemArray[i].itemIsKey() && gotKey == false)
		{
			gotKey = true;
			itemArray[i] = nonItem;
		}
	}
	return gotKey;
}

/******************************************************************************
*							Container::hasTheBee
* Getter for redPotion. DOES NOT use it when found.
******************************************************************************/
bool Container::hasTheBee()
{
	bool gotBee = false;

	for (int i = 0; i < 3; i++)
	{
		if (!itemArray[i].itemIsFake() && itemArray[i].itemIsBee() && gotBee == false)
		{
			gotBee = true;
		}
	}
	return gotBee;
}

/******************************************************************************
*							Container::hasTheFairy
* Getter for fairy. Uses it when found.
******************************************************************************/
bool Container::hasTheFairy()
{
	bool gotFairy = false;

		for (int i = 0; i < 3; i++)
		{
			if (!itemArray[i].itemIsFake() && itemArray[i].itemIsFairy() && gotFairy == false)
			{
				gotFairy = true;
				itemArray[i] = nonItem;
			}
		}
		return gotFairy;
}
