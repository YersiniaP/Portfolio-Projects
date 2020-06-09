/******************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/12/2019
* Description:		Class to hold Item objects. The constructor initialized the
*					array with empty items and another function can be used to
* add Items to an empty slot. There is a function to print the contents of the
* array. The remaining functions are getters for the Items.
******************************************************************************/
#include "Item.h"

#ifndef CONTAINER_HPP
#define CONTAINER_HPP
class Container
{
	private:

		Item nonItem;
		Item itemArray[3];

	public:
		Container();

		void printContainer();

		void addItem(Item);

		bool hasRedPotion();

		bool hasTheKey();

		bool hasTheBee();

		bool hasTheFairy();
};
#endif