/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 2: Creating Complex Menus from File                                             *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: Ex2_Menu.txt                                                          *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	Screen primary; //Declaring primary Screen object.

	Window menu; //Declaring the primary menu Window object.


	/*Declaring some dynamic menu elements (i.e. character name, class, HP, etc.).*/

	string cname = "Trogdor"; 
	string cclass = "Burninator";
	string cHP = "1000/1000"; //Numeric elements must be converted to string before being referenced.
	string cMP = "300/450";
	string exp = "345";
	string level = "12";
	string gold = "1124";
	string time = "11:23:45";


	primary.addlayer (&menu); //Adding the menu to the primary screen.

	menu.loadfromfile ("Ex2_Menu.txt"); //Loading the Menu design from file.


	/*Setting the empty active text specifier to their respective string values. These active text specifier spaces are read and numbered from left to right and top to bottom.*/

	menu.setactivetext (0, cname);
	menu.setactivetext (1, cclass);
	menu.setactivetext (2, level);
	menu.setactivetext (3, cHP);
	menu.setactivetext (4, cMP);
	menu.setactivetext (5, exp);
	menu.setactivetext (6, gold);
	menu.setactivetext (7, time);


	menu.setcursor (0, true); //Making the first cursor position visible.


	primary.displayscr (); //Displaying primary screen contents.

	return 0;

	/*At this point read the documentation on changing special menu construction characters, and explore irregular menu shapes.*/
}
	