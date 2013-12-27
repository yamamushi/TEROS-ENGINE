/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 6: Loading and Saving R3Objects from File (Pt. 1 - Saving to File)              *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 22 December 2013                                                         *
* Associated Files: Ex6_2.cpp, Ex6_3DModel1.tr3, Ex6_3DModel_2.tr3                        *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

int main ()
{
	/******This portion of the example code is derived from Ex5.cpp******/



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



	/*****End of code derived from Ex5.cpp*****/



	cube.saveobj ("Ex6_3DModel_1"); //Saving the cube object as it is defined above to a file called 'Ex5_3DModel_1.tr3'.

	return 0;

	/*It should be noted that any rotations, rotational settings, or R3Object links applied to the cube prior to writing the R3Object to file are not saved. Only coordinate information describing the original, unrotated object, its current position, and special character settings is saved.*/
}