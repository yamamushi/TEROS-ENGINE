/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 3: Overlaying Multiple Windows                                                  *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: Ex3_Menu.txt, Ex3_Submenu.txt                                         *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	Screen primary; //Declaring primary Screen object.

	Window menu; //Declaring primary menu object.
	Window submenu; //Declaring secondary menu object.


	primary.addlayer (&menu); //Adding primary menu as the first layer (background) on the primary screen.
	primary.addlayer (&submenu); //Adding submenu as the second layer (foreground) on the primary screen.


	/*Loading menu resources from file.*/

	menu.loadfromfile ("Ex3_Menu.txt");
	submenu.loadfromfile ("Ex3_Submenu.txt");


	submenu.tlrepos (25, 23); //Resetting the (x, y) position of the top left corner of the submenu to coordinates (25, 23).

	primary.displayscr (); //Outputting the primary screen layout.

	return 0;

	/*At this point it may be informative to try swapping the window layer positions; also, getting a feel for repositioning the windows wouldn't hurt.*/

}