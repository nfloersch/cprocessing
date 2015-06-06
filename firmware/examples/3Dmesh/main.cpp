/*
 * main.cpp
 *
 *  Created on: Sep, 16, 2011
 *      Author: esperanc
 */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#endif
#include <cprocessing.hpp>
#include <iostream>


using namespace cprocessing;
using namespace std;

#include "mesh.hpp"
#include "arcball.hpp"

Mesh mesh;
Arcball arcball (200,200,200);

void mouseDragged () {
    arcball.drag (pmouseX, pmouseY, mouseX, mouseY);
    
}

void setup() {
    size(400,400);
    mesh.loadPly ("monkey.ply");
    mesh.computeBounds();
    
    cout << mesh.vtx.size() << " vertices\n";
    cout << "center at " << mesh.boxcenter.x << "," << mesh.boxcenter.y << "," << mesh.boxcenter.z << "\n";  
    cout << "centroid at " << mesh.centroid.x << "," << mesh.centroid.y << "," << mesh.centroid.z << "\n";  
    cout << "box size " << mesh.boxsize.x << "," << mesh.boxsize.y << "," << mesh.boxsize.z << "\n";  
    cout << "box min " << mesh.boxmin.x << "," << mesh.boxmin.y << "," << mesh.boxmin.z << "\n";  
    cout << "box max " << mesh.boxmax.x << "," << mesh.boxmax.y << "," << mesh.boxmax.z << "\n";  
    cout << "radius " << mesh.radius << "\n";
    
    mesh.computeNormals();
}

static GLuint dlist = 99;


void draw() {
	background (0,0,100);
	//lights();
	perspective (PI/6, width*1.0/height, 0, 3*width);
	translate(width/2, height/2, -width);
	scale (width/(mesh.radius*2));
	applyMatrix(arcball.matrix);
	translate(-mesh.centroid.x, -mesh.centroid.y, -mesh.centroid.z); 
	//noFill();
	//stroke(255,255,255);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDepthFunc(GL_LESS);
	//glDisable(GL_DEPTH_TEST);
	glEnable (GL_CULL_FACE);
	if (dlist == 99) {
	dlist = glGenLists (1);
    glNewList(dlist, GL_COMPILE);

	glBegin(GL_TRIANGLES); //beginShape(TRIANGLES);
	for (unsigned idx = 0; idx < mesh.faceidx.size(); idx+=3) {
	    // Get vertex indices
        int i = mesh.faceidx[idx], j = mesh.faceidx[idx+1], k = mesh.faceidx[idx+2];
        // Generate the three vertices
        PVector &n = mesh.fnrm[idx/3];
        //normal (n.x, n.y, n.z);
	    glVertex3dv (mesh.vtx[i].array());//vertex (mesh.vtx[i].x, mesh.vtx[i].y, mesh.vtx[i].z);
	    glVertex3dv (mesh.vtx[j].array());//vertex (mesh.vtx[j].x, mesh.vtx[j].y, mesh.vtx[j].z);
	    glVertex3dv (mesh.vtx[k].array());//vertex (mesh.vtx[k].x, mesh.vtx[k].y, mesh.vtx[k].z);
	}
	glEnd();//endShape();
	
	glEndList();
	}
	glCallList (dlist);
}

