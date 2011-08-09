/*
 * graphics.cpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#include <GL/glut.h>
#include <iostream>
#include "cprocessing.hpp"

/// This will link with the client's functions
extern void draw();
extern void setup();
extern void mousePressed();
extern void mouseReleased();
extern void mouseMoved();
extern void mouseDragged();
extern void keyPressed();
extern void keyReleased();


namespace cprocessing {

	//
    // Global variables
	//

	int mouseX = 0;  ///< Mouse x coordinate
	int mouseY = 0;  ///< Mouse y coordinate
	int pmouseX = 0;  ///< Previous mouse x coordinate
	int pmouseY = 0;  ///< Previous mouse y coordinate
	bool mousePressed = false; ///< Whether any mouse button is pressed
	int mouseButton = LEFT; ///< Which button is pressed
	bool keyPressed = false; ///< Whether a key was pressed
	unsigned char key; ///< Which (ASCII) key was pressed
	int keyCode;   ///< Code for the last pressed key

	int width;     ///< window width
	int height;    ///< window height

	unsigned config = HALF_PIXEL_SHIFT | Y_DOWN; ///< Configuration flags

	int frameRate = 60; ///< Frames per second

	int initialized = false; 	///< Whether or not initialization of glut took place

	color strokeColor (0,0,0);     ///< Line drawing color
	color fillColor   (255,255,255);   ///< Area drawing color

    /// This is called for each frame
    static void display () {

        // Default transformation
        camera();
        perspective();

        // Call external display function
        ::draw();

        // End by swapping front and back buffers
        glutSwapBuffers() ;
    }

    /// Called whenever window geometry is changed.
    /// @param wid New width of the window.
    /// @param hgt New height of the window.
    static void reshape (int wid, int hgt)
    {
        glViewport(0,0,wid,hgt);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glPolygonOffset (1., -1.);

        width = wid;
        height = hgt;

        // Default background is gray 70%
        background (200);
        glutSwapBuffers();
    }

    /// The refresh function is called periodically to redisplay
    static void refresh (int) {
    	glutPostRedisplay();
    	glutTimerFunc (1000/frameRate, refresh, 0);
    }

    /// Called whenever mouse moves
    static void mousemotion (int x, int y) {
    	pmouseX = mouseX;
    	pmouseY = mouseY;
    	mouseX = x;
    	mouseY = y;
    	if (mousePressed) {
    		::mouseDragged();
    	} else {
    		::mouseReleased();
    	}
    }

    /// Called whenever mouse button is pressed
    static void mouse (int button, int state, int x, int y) {
    	pmouseX = mouseX;
    	pmouseY = mouseY;
    	mouseX = x;
      	mouseY = y;
      	mousePressed = state == GLUT_DOWN;

      	if (button == GLUT_LEFT_BUTTON) {
      		mouseButton = LEFT;
      	} else if (button == GLUT_RIGHT_BUTTON) {
      		mouseButton = RIGHT;
      	} else {
      		mouseButton = CENTER;
      	}
      	if (mousePressed) {
      		::mousePressed();
      	}
      	else {
      		::mouseReleased();
      	}

    }

    /// Called whenever a key is pressed
    static void keyboard (unsigned char ch, int x, int y) {
    	keyPressed = true;
    	key = ch;
    	keyCode = ch;
    	::keyPressed();
    }

    /// Called whenever a key is released
    static void keyboardup (unsigned char ch, int x, int y) {
    	keyPressed = false;
    	::keyReleased();
    }

    /// Called whenever a special key is pressed
    static void special (int ch, int x, int y) {
    	keyPressed = true;
    	key = CODED;
    	keyCode = 0;
    	switch (ch) {
			case GLUT_KEY_F1:
			case GLUT_KEY_F2:
			case GLUT_KEY_F3:
			case GLUT_KEY_F4:
			case GLUT_KEY_F5:
			case GLUT_KEY_F6:
			case GLUT_KEY_F7:
			case GLUT_KEY_F8:
			case GLUT_KEY_F9:
			case GLUT_KEY_F10:
			case GLUT_KEY_F11:
			case GLUT_KEY_F12:
				keyCode = ch + F1 - GLUT_KEY_F1;
				break;
			case GLUT_KEY_LEFT:
				keyCode = LEFT;
				break;
			case GLUT_KEY_UP:
				keyCode = UP;
				break;
			case GLUT_KEY_RIGHT:
				keyCode = RIGHT;
				break;
			case GLUT_KEY_DOWN:
				keyCode = DOWN;
				break;
			case GLUT_KEY_PAGE_UP:
				keyCode = PAGEUP;
				break;
			case GLUT_KEY_PAGE_DOWN:
				keyCode = PAGEDOWN;
				break;
			case GLUT_KEY_HOME:
				keyCode = HOME;
				break;
			case GLUT_KEY_END:
				keyCode = END;
				break;
			case GLUT_KEY_INSERT:
				keyCode = INSERT;
				break;
    	}
    	::keyPressed();
    }

    /// Called whenever a special key is released
    static void specialup (int ch, int x, int y) {
    	keyPressed = false;
    	::keyReleased();
    }

    /// Sets up a window of the given size
    /// @param wid Desired window width in pixels.
    /// @param hgt Desired window height in pixels.
    /// @param name Desired window title.
    void size (unsigned wid, unsigned hgt, const char* name) {
    	if (initialized) {
    		glutReshapeWindow (wid, hgt);
    		glutSetWindowTitle (name);
    	} else {
			glutInitWindowSize (wid, hgt);
			width = wid;
			height = hgt;
			glutCreateWindow (name);
			glutReshapeFunc(reshape);
			glutDisplayFunc(display);
			glutMotionFunc (mousemotion);
			glutPassiveMotionFunc (mousemotion);
			glutMouseFunc (mouse);
			glutKeyboardFunc (keyboard);
			glutKeyboardUpFunc (keyboardup);
			glutSpecialFunc(special);
			glutSpecialUpFunc(specialup);
			//glutShowWindow();
			initialized = true;
    	}

    }

    /// Initializes and runs the application main event loop
    void run() {
		int argc = 0;
		char **argv = 0;
		glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    	glutTimerFunc (1000/frameRate, refresh, 0);
    	bezierDetail(50);
    	::setup();
        glutMainLoop();
    }
}
