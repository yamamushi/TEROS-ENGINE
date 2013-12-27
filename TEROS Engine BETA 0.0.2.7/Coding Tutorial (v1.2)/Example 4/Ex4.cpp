/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 4: Loading Window Content from Vector                                           *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: NA                                                                    *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	Screen primary; //Declaring primary Screen object.

	Window content; //Declaring a Window object to hold the programmatic vector content.

	vector <char> pattern (0); //Declaring a character vector to hold the content to be loaded into the Window object.


	primary.addlayer (&content); //Adding the content window to the screen.


	/*Creating a checker pattern within the character vector.*/

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 78; j++)
		{
			pattern.resize (pattern.size () + 1);
			pattern [pattern.size () - 1] = ((i + j)%2) == 0 ? ' ' : '#';
		}
	}


	content.loadfromvector (pattern, 78); //Loading the character vector information into the content window. The number of columns is specified in the arguments.

	primary.displayscr (); //Outputting the screen contents.

	return 0;

	/*This might seem a bit unintuitive at first, so you might want to try doing this with a vector containing more complex information.*/

}