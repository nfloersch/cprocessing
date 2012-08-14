/**
 * file: main.cpp
 *
 * Plots a cylindrical shaded line connecting points in 3D
 *
 *  Created on: Aug 8, 2012
 *      Author: esperanc
 */

#include <cprocessing.hpp>
#include <vector>

using namespace cprocessing;

typedef std::vector<PVector> Polygon;

///
/// Returns the vertices of a circular cross-section as a polygon.
/// @param p the circle center.
/// @param normal the circle normal (unit vector).
/// @param up the direction where the first vertex of the circle will be placed -
///   all other vertices are obtained by rotating this vector around the normal.
/// @param r radius of the circle.
/// @param n number of sides of the polygon.
/// @return a vector of points with the vertices of a polygon that approximate the circle.
///
inline Polygon cross_section(PVector p, PVector normal, PVector up, double r, int n) {

    PMatrix sectorRot = PMatrix::rotationMatrix(TWO_PI/n, normal.x, normal.y, normal.z);
    Polygon poly;
    
    for (int i = 0; i < n; i++) {
        poly.push_back (p + up * r);
        up = sectorRot.transformVector (up);
    }
    
    return poly;
}


/// Draws a cylinder with base in p0 and top in p1. 
/// @param p0: position of the base of the cylinder.
/// @param p1: position of the top of the cylinder.
/// @param up0: unit vector establishing the tilt of the cross section
///     at p0. In particular, the plane of the cross section contains up0 and
///     the cross product of up0 and (p1-p0).
/// @param up1: unit vector establishing the tilit of the cross section at p1.
/// @param r0: radius of the cross section at p0.
/// @param r1: radius of the cross section at p1.
/// @param nsides: number of vertices in each cross section.
/// @param nrows: how many cross sections are going to be drawn.
void cylinder (PVector p0, PVector p1, PVector up0, PVector up1, double r0, 
               double r1, int nsides, int nrows) {
    
    if (nsides < 2) nsides = 2;
    if (nrows < 2) nrows = 2;
    up0.normalize();
    up1.normalize();
    
    PVector v = p1 - p0;
	if (v.mag() < EPS) v = up1 - up0;
	if (v.mag() < EPS) return;
    Polygon last;
    PVector plast;

    for (int i = 0; i < nrows; i++) {
        double t = map (i, 0, nrows-1, 0, 1);
        PVector up = up0 * (1-t) + up1 * t; up.normalize();
        PVector p = p0 * (1-t) + p1 * t;
        double r = r0 * (1-t) + r1 * t;
        PVector u = up . cross (v) . cross (up);
        u.normalize();
        Polygon next = cross_section (p, u, up, r, nsides);
        if (i != 0) {
            beginShape(QUAD_STRIP);
            for (int j = 0; j <= nsides; j++) {
                int k = j % nsides;
                PVector& a = last [k];
                PVector an = a - plast; an.normalize();
                normal (an.x, an.y, an.z);
                vertex (a.x, a.y, a.z);
                PVector& b = next [k];
                PVector bn = b - p; bn.normalize();
                normal (bn.x, bn.y, bn.z);
                vertex (b.x, b.y, b.z);
                                
            }
            endShape();
        }
        last = next;
        plast = p;
    }
}

/// Draws a polygonal line poly as a tube.
/// @param poly polygonal line vertices.
/// @param r radius of the tube
/// @param nsides number of sides for rendering each cylinder.
/// @param nrows number of rows for rendering each cylinder
void cylinderLine (Polygon poly, int r, int nsides = 16, int nrows = 8) {
	if (poly.size() < 2) return;
	
	PVector lastTangent(1,0,0);
	PVector lastNormal(0,0,1);
	for (int i = 1; i < poly.size(); i++) {
		PVector tangent = poly[i] - poly[i-1];
		if (tangent.mag() < EPS) tangent = lastTangent;
		else tangent.normalize();
		PVector normal = lastNormal;
		if (i+1 < poly.size()) {
			normal = (poly [i+1] - poly [i]).cross(tangent);
			if (normal.mag() < 0.000001) normal = lastNormal;
			else if (i == 1) lastNormal = normal;
			normal.normalize();
			if (lastNormal.dot(normal)<0) normal = PVector(0,0,0)-normal;
		}
		PVector up0 = tangent.cross(lastNormal);
		PVector up1 = tangent.cross(normal);
		cylinder(poly[i-1], poly[i],tangent.cross(lastNormal), tangent.cross(normal), r, r, nsides, nrows);
		if (i+1 < poly.size()) {
		    PVector nextTangent = poly[i+1] - poly[i];
		    cylinder(poly[i], poly[i],tangent.cross(normal), nextTangent.cross(normal), r, r, nsides, nrows);
		}
		lastNormal = normal;
		lastTangent = tangent;
	}
}

// Where the line is stored
Polygon poly;

// Mouse callback: start a new line
void mousePressed() {
    poly.clear();
    poly.push_back (PVector (mouseX, mouseY, 0));
}

// Mouse drag callback: Add a new point  to line
void mouseDragged() {
    if (dist (mouseX, mouseY, poly.back().x, poly.back().y) < 5) return;
    poly.push_back (PVector (mouseX, mouseY, 0));
}

// setup
void setup() {
    size (400,400);
}

// draw callback
void draw() {
	background (200);
	noStroke();
	fill (255,0,0);
	lights();
	cylinderLine (poly, 20);
}

