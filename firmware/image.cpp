/*
 * image.cpp
 *
 *  Created on: Sep 16, 2011
 *      Author: claudio
 *
 *  Image support
 */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#endif
#include <cassert>
#include <iostream>
#include "cprocessing.hpp"

using namespace cprocessing;

namespace cprocessing {

    /// Constructor
    /// @arg width horizontal size
    /// @arg height vertical size
    /// @arg type ARGB, RGB or ALPHA
    PImage::PImage (int width, int height, int type) {
    
        // Simple argument checking
        assert (width>=0 && height>=0 && width < 1e6 && height < 1e6 && 
                (type == ARGB || type == RGB || type == ALPHA));  
                
        this->width = width;
        this->height = height;
        this->pixels = new color[width*height];
        
    }
    
    /// Destructor
    PImage::~PImage () {
        delete pixels;
    }
    
    
    /// Draws the image at position (x, y) of the screen
    void PImage::put (int x, int y) {
    
        // invert y coordinate
        if (config&Y_DOWN) {
            y = y + height;
        }
        
        // set write position
        glRasterPos2i (x,y);
        
        // write
        glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) pixels);
            
    }

    
}

