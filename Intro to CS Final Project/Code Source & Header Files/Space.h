/****************************************************************************
* Program Name:		Final Project
* Author:			Sarah Leon
* Date:				08/11/2019
* Decription:		The Space Class has 4 pointers (to other spaces) representing
*					up, down, left, and right. The other data member is a bool
* for map printing purposes. A default constructor sets the pointers to null, 
* while the other sets them to passed spaces. Two virtual abstract functions 
* are overridden in derived classes. Two other functions facilitate the map
* representation of the square. The remaining functions are pointer setters
* and getters.
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
protected:
	Space* right;				
	Space* left;
	Space* up;					
	Space* down;

	bool hasLink;

public:
	Space();
	Space(Space*, Space*, Space*, Space*);	

	void setRight(Space*);		
	void setLeft(Space*);
	void setUp(Space*);			
	void setDown(Space*);

	virtual void describeSquare() = 0;
	virtual void interactSpace() = 0;

	void toggleLink();
	char showLink();
		

	Space* moveRight();			
	Space* moveLeft();
	Space* moveUp();
	Space* moveDown();			
};

#endif