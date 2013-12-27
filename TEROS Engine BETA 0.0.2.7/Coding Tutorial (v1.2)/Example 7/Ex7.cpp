/******************************************************************************************
* TEROS ENGINE BETA 0.0.2.7 Development Tutorial                                          *
* Example 7: Creating Advanced Three-Dimensional Object Classes                           *
*                                                                                         *
* Author: Kyle L. Miskell                                                                 *
* Last Modified: 27 December 2013                                                         *
* Associated Files: chest.tr3, lid.tr3                                                    *
*                                                                                         *
******************************************************************************************/

#include "teros.h"

using namespace std;

class TreasureChest //Declaring a new class, derivative of the R3Object class, for our advanced 'TreasureChest' object.
{
	private:
		R3Object chest; //Declaring an R3Object within the TreasureChest class template to hold the dynamic, instantaneous 3D data for our whole TreasureChest object.
		R3Object lid; //Declaring another R3Object to hold the static 3D data for the lid of the chest--the moving component of this advanced 3D object.

		vector <Polygon> lidbuffer; //Declaring a vector of Polygons to temporarily hold the instantaneous, transformed lid polygons.
	public:
		TreasureChest (); //Prototyping a constructor function for our TreasureChest class.

		void openlid (double); //Prototyping a function for opening the lid of the chest to a certain angle (in radians).
		void movechest (double, double, double); //Prototyping a function for moving the entire chest object and its hidden static component, 'lid,' about a 3D Cartesian coordinate system.
		void rotchest (char, double); //Prototyping a function for rotating the instanteous 3D model for the chest about a given axis and through a specified angle.

		R3Object * putchest (); //Prototyping a function for returning a pointer to the 'chest' R3Object contained within a given TreasureChest object.
		R3Object * putlid (); //Prototyping a function for returning a pointer to the 'lid' R3Object contained within a given TreasureChest object.
};

TreasureChest::TreasureChest ()
{
	chest.loadobj ("chest.tr3"); //Loading the 3D model for the chest (without the lid) from file.
	lid.loadobj ("lid.tr3"); //Loading the 3D model for the lid from file.

	lid.ctrscaleoff (3.00, 2.50, 2.00); //Setting the lid to pivot about the hinge point of the chest.

	lidbuffer = lid.permcpy (); //Copying the unrotated lid data to the Polygon buffer vector.

	for (int i = 0; i < lidbuffer.size (); i++)
	{
		chest.addside (&lidbuffer [i]); //Adding the unrotated lid data to the main body of the chest.
	}

	chest.ctrscaleoff (chest.centerx (), chest.centery (), chest.centerz ()); //Setting the whole chest (lid and main body) to rotate about the geometric center of an idealized, unopened chest.

	chest.addolink (&lid, true); //Object linking the R3Object containing the whole chest with the R3Object containing the untransformed lid data.
}

void TreasureChest::openlid (double angle)
{
	lid.basisreset (); //Resetting the rotation basis for the lid, such that the lid opens to the angle specified, rather than the last angle plus the current specified angle.

	lid.rot ('y', angle); //Rotating the lid to the specified angle about the hinge position.

	lidbuffer.resize (0); //Clearing the lidbuffer.

	lidbuffer = lid.permcpy (); //Filling the lidbuffer with new transformed/opened lid data.

	for (int i = chest.sidenum () - lidbuffer.size (); i < chest.sidenum (); i++) //Updating the 'chest' R3Object to reference the refreshed lid data.
	{
		chest.modside (i, &lidbuffer [i + lidbuffer.size () - chest.sidenum ()]);
	}
}

void TreasureChest::movechest (double xdisp, double ydisp, double zdisp)
{
	double scalepchest [3]; //Declaring a 3-tuple double array to hold the scaling and rotation point (unopened geometric center) specified for the chest.
	double scaleplid [3]; //Declaring a 3-tuple double array to hold the scaling and rotation point (hinge coordinates) specified for the lid.

	chest.cpyscalep (scalepchest); //Loading the coordinates of the chest scaling and rotation point.
	lid.cpyscalep (scaleplid); //Loading the coordinates of the lid scaling and rotation point.

	chest.shiftctr (xdisp, ydisp, zdisp); //Repositioning the chest and, due to the object linkage, the lid the specified distance on each coordinate axis.

	chest.ctrscaleoff (scalepchest [0] + xdisp, scalepchest [1] + ydisp, scalepchest [2] + zdisp); //Updating the scaling and rotation point of the chest to compensate for the positional shift.
	lid.ctrscaleoff (scaleplid [0] + xdisp, scaleplid [1] + ydisp, scaleplid [2] + zdisp); //Updating the scaling and rotation point of the lid to compensate for the positional shift.
}

void TreasureChest::rotchest (char axis, double angle) //The simplicity of this function makes it a bit redundant, but, nevertheless, it is defined for parallelism's sake.
{
	chest.rot (axis, angle); //Rotating the chest R3Object about the specified axis through a given angle (in radians).
}

R3Object * TreasureChest::putchest ()
{
	return &chest; //Returning a pointer to the chest R3Object.
}

R3Object * TreasureChest::putlid ()
{
	return &lid; //Returning a pointer to the lid R3Object.
}

int main ()
{
	Screen primary; //Declaring the primary output Screen object.

	Window cartesian; //Declaring the output Window for the 3D display.

	R3Cam camera; //Declaring the 3D camera object (initially placed at coordinates (0, 0, 0)).

	TreasureChest chest0; //Declaring an example TreasureChest object.


	/*Insert TreasureChest class commands, such as openlid, movechest, and rotchest here to view the effects of these functions.*/


	primary.addlayer (&cartesian); //Adding the 3D output window to the screen.

	camera.setviewsize (40, 78); //Setting the view size of the 3D camera object.

	camera.setcampos (-5.00, 3, 1.50); //Adjusting the camera position to center its view of the object.

	camera.addobject (chest0.putchest ()); //Adding the instantaneous R3Object data for chest0 to the camera's field of vision.

	camera.drawobjects (); //Calculating and drawing the 3D perspective to the camera's output vector.

	cartesian.loadfromvector (camera.putview (), 78); //Dumping the newly constructed camera image to the window.

	primary.displayscr (); //Outputting the screen contents to the terminal.

	return 0;

	/*This is only one possible way of implementing an advanced object in the TEROS Engine. The purpose of this example is primarily to clarify the meaning and intent of advanced object functionality.*/
}