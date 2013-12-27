/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 5: Constructing and Displaying a Simple 3D Shape in Three-Space                 *
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
	Screen primary; //Declaring the primary output Screen object.

	Window cartesian; //Declaring the output Window for the 3D display.

	R3Cam camera; //Declaring the 3D camera object (initially placed at coordinates (0, 0, 0)).

	R3Object cube; //Declaring the 3D container object for a cube.



	/*Declaring Polygon objects for all of the polygons used in constructing a simple cube (the TEROS Engine uses triangular polygons).*/

	Polygon ls1;
	Polygon ls2;
	Polygon rs1;
	Polygon rs2;
	Polygon bs1;
	Polygon bs2;
	Polygon fs1;
	Polygon fs2;
	Polygon ts1;
	Polygon ts2;
	Polygon us1;
	Polygon us2;


	/*Manually setting the Cartesian coordinates and character textures for each of the twelve polygons comprising the cube.*/

	ls1.modp (0, 2.5, -0.5, -0.5);
	ls1.modp (1, 3.5, -0.5, -0.5);
	ls1.modp (2, 3.5, -0.5, 0.5);
	ls1.setfill ('@');

	ls2.modp (0, 3.5, -0.5, 0.5);
	ls2.modp (1, 2.5, -0.5, 0.5);
	ls2.modp (2, 2.5, -0.5, -0.5);
	ls2.setfill ('@');

	rs1.modp (0, 2.5, 0.5, -0.5);
	rs1.modp (1, 3.5, 0.5, -0.5);
	rs1.modp (2, 3.5, 0.5, 0.5);
	rs1.setfill ('@');

	rs2.modp (0, 3.5, 0.5, 0.5);
	rs2.modp (1, 2.5, 0.5, 0.5);
	rs2.modp (2, 2.5, 0.5, -0.5);
	rs2.setfill ('@');

	bs1.modp (0, 3.5, -0.5, -0.5);
	bs1.modp (1, 3.5, 0.5, -0.5);
	bs1.modp (2, 3.5, 0.5, 0.5);
	bs1.setfill ('#');

	bs2.modp (0, 3.5, 0.5, 0.5);
	bs2.modp (1, 3.5, -0.5, 0.5);
	bs2.modp (2, 3.5, -0.5, -0.5);
	bs2.setfill ('#');

	fs1.modp (0, 2.5, -0.5, -0.5);
	fs1.modp (1, 2.5, 0.5, -0.5);
	fs1.modp (2, 2.5, 0.5, 0.5);
	fs1.setfill ('#');

	fs2.modp (0, 2.5, 0.5, 0.5);
	fs2.modp (1, 2.5, -0.5, 0.5);
	fs2.modp (2, 2.5, -0.5, -0.5);
	fs2.setfill ('#');

	ts1.modp (0, 3.5, -0.5, 0.5);
	ts1.modp (1, 3.5, 0.5, 0.5);
	ts1.modp (2, 2.5, 0.5, 0.5);
	ts1.setfill ('X');

	ts2.modp (0, 2.5, 0.5, 0.5);
	ts2.modp (1, 2.5, -0.5, 0.5);
	ts2.modp (2, 3.5, -0.5, 0.5);
	ts2.setfill ('X');

	us1.modp (0, 3.5, -0.5, -0.5);
	us1.modp (1, 3.5, 0.5, -0.5);
	us1.modp (2, 2.5, 0.5, -0.5);
	us1.setfill ('X');

	us2.modp (0, 2.5, 0.5, -0.5);
	us2.modp (1, 2.5, -0.5, -0.5);
	us2.modp (2, 3.5, -0.5, -0.5);
	us2.setfill ('X');


	/*Adding the Polygon objects to the 3D object container.*/

	cube.addside (&ls1);
	cube.addside (&ls2);
	cube.addside (&rs1);
	cube.addside (&rs2);
	cube.addside (&bs1);
	cube.addside (&bs2);
	cube.addside (&fs1);
	cube.addside (&fs2);
	cube.addside (&ts1);
	cube.addside (&ts2);
	cube.addside (&us1);
	cube.addside (&us2);

	
	primary.addlayer (&cartesian); //Adding the 3D output window to the screen.

	camera.setviewsize (40, 78); //Setting the view size of the 3D camera object.

	camera.addobject (&cube); //Adding the cube to the 3D camera's field of vision.

	camera.drawobjects (); //Calculating and drawing the 3D perspective to the camera's output vector.

	cartesian.loadfromvector (camera.putview (), 78); //Dumping the newly constructed camera image to the window.

	primary.displayscr (); //Outputting the screen contents to the terminal.

	return 0;

	/*Try performing some rotations and translations on the camera and the object. You can also change the zoom factor of the camera, among other properties.*/

}