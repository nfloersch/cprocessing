/*
 * attributes.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: claudio
 */

#include <GL/glut.h>
#include <cmath>
#include "cprocessing.hpp"

namespace cprocessing {
	//
	// Attributes
	//

	inline unsigned char clamp(double v) {
		return v > 255 ? 255 : v < 0 ? 0 : (unsigned char) v;
	}

    // Simple hsv to rgb conversion. Assumes components specified in range 0.0-1.0.
	static void hsb_to_rgb (double h, double s, double v,
			                double& r, double& g, double& b)
	{
	    double tmp = h*5.9999;
	    int hi = int (tmp);
	    double f = tmp-hi;
	    double p = v * (1-s);
	    double q = v * (1-f*s);
	    double t = v * (1-(1-f)*s);
	    if (hi==0) {
	        r = v; g = t; b = p;
	    } else if (hi==1) {
	        r = q; g = v; b = p;
	    } else if (hi==2) {
	        r = p; g = v; b = t;
	    } else if (hi == 3) {
	        r = p; g = q; b = v;
	    } else if (hi == 4) {
			r = t; g = p; b = v;
		} else {
			r = v; g = p; b = q;
		}
	}

	// Some useful defines
	inline double max (double a, double b) { return a>b? a: b; }
	inline double min (double a, double b) { return a<b? a: b; }

	// Simple rgb to hsb conversion. Assumes components specified in range 0.0-1.0.
	static void rgb_to_hsb (double r, double g, double b,
			                double& h, double& s, double& v)
	{
	    double maxval = max(max(r,g),b);
	    double minval = min(min(r,g),b);
	    if (maxval==minval) {
	        h = 0.0;
	    } else if (maxval==r) {
	        h = fmod (60 * (g-b)/(maxval-minval) + 360, 360) / 360.0;
	    }
	    else if (maxval==g) {
	        h = (60 * (b-r)/(maxval-minval) + 120) / 360.0;
	    } else {
	        h = (60 * (r-g)/(maxval-minval) + 240) / 360.0;
	    }

	    if (maxval==0.0) {
	        s = 0.0;
	    } else {
	        s = (maxval-minval)/maxval;
	    }
	    v = maxval;
	}

	// Constructor for the color class
	color::color(double R, double G, double B, double A) {
		rgba[0] = clamp(R);
		rgba[1] = clamp(G);
		rgba[2] = clamp(B);
		rgba[3] = clamp(A);
	};


	/// Sets line color
	/// @param color: New line color
	void stroke (const color& c) {
		strokeColor = c;
	}

	/// Sets area color
	/// @param color: New area color
	void fill (const color& c) {
		fillColor = c;
	}

	/// Sets line / point width
	/// @param weight: New breadth of line in pixels
	void strokeWeight (int weight) {
		glLineWidth (weight);
		glPointSize (weight);
	}


	/// Clear the window with a background color
	/// @param color: background color
	void background (const color& c) {
		glClearColor (c.rgba[0] * (1.0/255),
				      c.rgba[1] * (1.0/255),
				      c.rgba[2] * (1.0/255),
				      c.rgba[3] * (1.0/255));
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	/// Sets state so that lines are rendered antialiased.
	void smooth() {
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	    glEnable(GL_LINE_SMOOTH);
	    glEnable(GL_POINT_SMOOTH);
	    glEnable(GL_POLYGON_SMOOTH);
	    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	}

	/// Sets state so that lines are rendered quickly.
	void noSmooth() {
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	    glDisable(GL_LINE_SMOOTH);
	    glDisable(GL_POINT_SMOOTH);
	    glDisable(GL_POLYGON_SMOOTH);
	}

}
