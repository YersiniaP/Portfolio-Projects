/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		Generic catch-all class for all items. The 'items' Link can
* collects in uses are stored simply as the bool data members (only one bool can
* be true per item). The default constructor makes an empty (all false) item and
* the other uses a passed integer to toggle one of the data members. There is a
* function to print a corresponding representation for the Utility Belt. The
* remaining functions are getters for the data members.
******************************************************************************/
#include <iostream>
#include "Item.h"

using std::cout;
using std::endl;

/******************************************************************************
*							TorchSpace::TorchSpace - Default
* Initializes the data memeber to false
******************************************************************************/
Item::Item()
{
	redPotion = false;
	bee = false;
	fairy = false;
	key = false;
}
/******************************************************************************
*							TorchSpace::TorchSpace
* Creates a specific item by switching one of the data members to true with the 
* passed integer.
******************************************************************************/
Item::Item(int itemType)
{
	redPotion = false;
	bee = false;
	fairy = false;
	key = false;

	switch (itemType)
	{
	case 1: redPotion = true;
		break;
	case 2: fairy = true;
		break;
	case 3: bee = true;
		break;
	case 4: key = true;
	}
}

/******************************************************************************
*							TorchSpace::showTorch
* How an item is printed in the Utility Belt.
******************************************************************************/
void Item::printItem()
{

	if (redPotion == true)
	{
		cout << "(R)";
	}
	if (bee == true)
	{
		cout << "(B)";
	}
	if (fairy == true)
	{
		cout << "(F)";
	}
	if (key == true)
	{
		cout << "KEY";
	}
}

//getters for bool variable
bool Item::itemIsRed()
{
	return redPotion;
}

bool Item::itemIsKey()
{
	return key;
}

bool Item::itemIsBee()
{
	return bee;
}

bool Item::itemIsFairy()
{
	return fairy;
}

//getter for empty item
bool Item::itemIsFake()
{
	if (redPotion == false && fairy == false && bee == false && key == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
