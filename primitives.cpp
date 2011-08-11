/*
 * primitives.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: claudio
 *
 *  Functions for drawing basic primitives
 */

#include <GL/glut.h>
#include <vector>
#include <cassert>
#include "cprocessing.hpp"

using namespace cprocessing;

static unsigned ellipseMode = CENTER; ///< Ellipse drawing mode
static std::vector<PVector> ellipseVtx;  ///< Vertices of circle centered at the origin and diameter 1

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
			// Draw point using the stroke color
			glColor4ubv (strokeColor.rgba);
			glBegin (GL_POINTS);
			glVertex3d (x,y,z);
			glEnd();
		}
	}
	
		
	/// Configures the number of line segments used for drawing an ellipse
	/// @arg n: number of sides
	void ellipseDetail (unsigned n) {
		ellipseVtx.clear();
		for (unsigned i = 0; i < n; i++) {
			double ang = M_PI * 2 * i / n;
			double x = cos(ang)/2;
			double y = sin(ang)/2;
			ellipseVtx.push_back (PVector (x, y, 0)); 
		}
	}
	
	/// Configures the way the 'ellipse' function interprets its arguments
	/// @arg mode: either CENTER, RADIUS, CORNER or CORNERS
	void ellipseMode (unsigned mode) {
		assert (mode == CENTER || mode == RADIUS || mode == CORNER || mode == CORNERS);
		::ellipseMode = mode;
	}
	
	
	/// Draws an ellipse. The meaning of the arguments depend on the current
	/// ellipseMode. By default:
	/// @arg x, y: center of the ellipse
	/// @arg width, height: size of the ellipse axes
	void ellipse (double x, double y, double width, double height) 
	{
		// Make changes to arguments to reflect the current ellipseMode
		switch (::ellipseMode) {
		case CENTER:
			x -= width/2;
        	y -= height/2;
        	break;
        case RADIUS:
		    x -= width;
		    y -= height;
		    width *= 2;
		    height *= 2;
		    break;
		case CORNERS:
		    width = width-x;
		    height = height-y;
		    break;
		}
		
		// Draw ellipse 
		glMatrixMode(GL_MODELVIEW);
	    glPushMatrix();
    	glTranslatef(x,y,0);
	    glScalef(width,height,1);
	    glTranslatef(0.5,0.5,0);
	    // activate and specify pointer to vertex array
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_DOUBLE, 0, ellipseVtx [0].array());
    	if (fillColor.rgba[3] > 0) {
			// See if filled ellipse is required
			glColor4ubv (fillColor.rgba);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_POLYGON,0,ellipseVtx.size());
    	}
    	if (strokeColor.rgba[3] > 0) {
			// See if filled ellipse is required
			glColor4ubv (strokeColor.rgba);
			glDrawArrays(GL_LINE_LOOP,0,ellipseVtx.size());
    	}
    	// deactivate vertex arrays after drawing
		glDisableClientState(GL_VERTEX_ARRAY);
		// Restore modelview
    	glPopMatrix();
    }
}
