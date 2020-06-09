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
#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	private:
		bool redPotion;
		bool bee;
		bool fairy;
		bool key;
	public:
		Item();
		Item(int);

		void printItem();

		bool itemIsRed();

		bool itemIsKey();

		bool itemIsBee();

		bool itemIsFairy();

		bool itemIsFake();
};
#endif