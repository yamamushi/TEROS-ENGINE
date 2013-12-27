/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 1: Intantiating, Loading (from file), and Displaying a Window Object            *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: Ex1_Content.txt                                                       *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	Screen primary; //Declaring the Screen object. The height and width of the screen are coded as macros in the teros.h header file. The default width is 131 characters, and the default height is 52 characters. This should be changed to around 78 x 40 characters for a standard MS Command Line terminal.

	Window example; //Declaring a Window object.


	primary.addlayer (&example); //Adding the example Window to the primary Screen.

	example.loadfromfile ("Ex1_Content.txt"); //The contents of the text file are loaded into the Window, and the window is resized to match the size of the input file. Any empty space in lines of less than maximal width are filled with the 'fill' character. Make sure to avoid special charaters for interactive window elements (check documentation file for special character presets); however, these special characters can be changed.

	primary.displayscr (); //Displays the screen contents.

	return 0;

	/*I would suggest playing around with some of the other Window and Screen class functions at this point to see how they work; however, some of these advanced functions are covered in later tutorials.*/
}