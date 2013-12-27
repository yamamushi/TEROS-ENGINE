/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 6: Loading and Saving R3Objects from File (Pt. 2 - Loading from File)           *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: Ex6_1.cpp, Ex6_3DModel_1.tr3, Ex6_3DModel_2.tr3                       *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	Screen primary; //Declaring the primary output Screen object.

	Window cartesian; //Declaring the output Window for the 3D display.

	R3Cam camera; //Declaring the 3D camera object (initially placed at coordinates (0, 0, 0)).

	R3Object object; //Declaring a generic R3Object container.


	object.loadobj ("Ex6_3DModel_1.tr3"); //Loading the R3Object saved in Ex6_1.cpp from the specified file.

	
	primary.addlayer (&cartesian); //Adding the 3D output window to the screen.

	camera.setviewsize (40, 78); //Setting the view size of the 3D camera object.

	camera.addobject (&object); //Adding the object to the 3D camera's field of vision.

	camera.drawobjects (); //Calculating and drawing the 3D perspective to the camera's output vector.

	cartesian.loadfromvector (camera.putview (), 78); //Dumping the newly constructed camera image to the window.

	primary.displayscr (); //Outputting the screen contents to the terminal.

	return 0;

	/*As further demonstration of the usefulness of the objsave/objload functions, try substituting "Ex6_3DModel_1.tr3" with "Ex6_3DModel_2.tr3" in the objload statement above to load a 3D model I created for the TEROS Engine BETA 0.0.2.7 demonstration video.*/
}