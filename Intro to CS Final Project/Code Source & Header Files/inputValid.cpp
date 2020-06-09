/****************************************************************************
 * Program Name:	Final Project (originally written for Project 1)
 * Author:		Sarah Leon
 * Date:		08/07/2019		
 * Description:		Source code for the inputValid function. The function
 * 			has three parameters: a string and two integers. The 
 * 			string is the prompt displayed to the user and the two
 * 			integers are the bounds that the user integer input 
 * 			must be between. The validated integer is then
 * 			returned.
 * ***************************************************************************/
#include <iostream>
#include <string>
#include <sstream>


using std::string;
using std::cout;
using std::cin;
using std::endl;


int inputValid(string prompt, int min, int max)	
{
	string userInput;	//user input to be validated
	string excess;		//string to hold any remaining string

	int validInt;			//input from user
	bool validStatus = false;	//User input is invalid until
					//verified otherwise
	
	cout << prompt << endl;		//displays prompt

	while (validStatus == false)	//loops while input is invalid
	{
		getline(cin, userInput);	//saves input as string

		//stream object created from user input
		std::stringstream stream(userInput); 

		//if the stream can be stored as an integer, 
		//and nothing is leftover after the integer		
		if (stream >> validInt && !(stream >> excess))
		{
			//and the integer is within the acceptable range
			if(validInt >= min && validInt <= max)
			{
				validStatus = true;	//then validated
				return validInt;		
			}
			
			else	//error message if integer out of range
			{
				cout << "That integer is not between ";
				cout << min << " and " << max << endl;
				
				cout << "Please try again" << endl;
			}
		}

		else 	//error message stream object isn't an integer
		{
			cout << "Invalid entry. Please try again." << endl;
		}
	}
}
