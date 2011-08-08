/*
 * primitives.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: claudio
 *
 *  Functions for drawing basic primitives
 */

#include <GL/glut.h>
#include "cprocessing.hpp"

namespace cprocessing {

	/// Draws a line segment in 3D
	/// @param x0: first vertex x coordinate
	/// @param y0: first vertex y coordinate
	/// @param z0: first vertex z coordinate
	/// @param x1: second vertex x coordinate
	/// @param y1: second vertex y coordinate
	/// @param z1: second vertex z coordinate
	void line (double x0, double y0, double z0, double x1, double y1, double z1) {
		if (strokeColor.rgba[3] > 0) {
			glColor4ubv (strokeColor.rgba);
			glBegin(GL_LINES);
			glVertex3d (x0, y0, z0);
			glVertex3d (x1, y1, z1);
			glEnd();
		}
	}


	/// Draws a filled triangle given the coordinates
	/// of its vertices.
	void triangle (double x0, double y0, double z0,
				   double x1, double y1, double z1,
				   double x2, double y2, double z2) {
		GLdouble vertices[] = {
				x0, y0, z0,
				x1, y1, z1,
				x2, y2, z2
		};
		// activate and specify pointer to vertex array
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_DOUBLE, 0, vertices);

		if (fillColor.rgba[3] > 0) {
			// See if filled triangle is required
			glColor4ubv (fillColor.rgba);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES,0,3);
		}
		if (strokeColor.rgba[3] > 0) {
			// See if outline triangle is required
			glColor4ubv (strokeColor.rgba);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawArrays(GL_TRIANGLES,0,3);
		}
		// deactivate vertex arrays after drawing
		glDisableClientState(GL_VERTEX_ARRAY);

	}

    /// Draws a filled 2D quadrilateral given the coordinates
	/// of its vertices.
    void quad (double x0, double y0,
		 	   double x1, double y1,
			   double x2, double y2,
			   double x3, double y3)
    {
    	GLdouble vertices[] = {
    					x0, y0,
    					x1, y1,
    					x2, y2,
    					x3, y3
    			};
		// activate and specify pointer to vertex array
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(2, GL_DOUBLE, 0, vertices);

		if (fillColor.rgba[3] > 0) {
			// See if filled triangle is required
			glColor4ubv (fillColor.rgba);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_QUADS,0,4);
		}
		if (strokeColor.rgba[3] > 0) {
			// See if outline triangle is required
			glColor4ubv (strokeColor.rgba);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawArrays(GL_QUADS,0,4);
		}
		// deactivate vertex arrays after drawing
		glDisableClientState(GL_VERTEX_ARRAY);

    }

	/// Draws a point.
	void point (double x, double y, double z)
	{
		if (strokeColor.rgba[3] > 0) {
			glColor4ubv (strokeColor.rgba);
			glBegin (GL_POINTS);
			glVertex3d (x,y,z);
			glEnd();
		}
	}

}
