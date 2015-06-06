/*
 * lights.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: claudio
 */

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#endif
#include "cprocessing.hpp"
#include <iostream>

static bool lights = false; ///< Whether lighting is turned on or off
static int lightCount = 0;  ///< How many light sources were defined
static float specular[4] = {0,0,0,1};   ///< Specular coefficients
static float constant = 1;    ///< Light attenuation coefficients
static float linear = 0;
static float quadratic = 0;

/// Turns lighting on
static void lightsOn()
{
    /// See if lights already on
    if (::lights) return;

    /// Turn on lighting but reset all light sources
    glEnable(GL_LIGHTING);
    ::lights = true;
    for (int i = 0; i < ::lightCount; i++) glDisable(GL_LIGHT0+i);
    ::lightCount = 0;

    // Make it possible to set material properties by using glcolor
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
	glEnable(GL_COLOR_MATERIAL);
}

namespace cprocessing {

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg nx, ny, nz: direction vector.
    void directionalLight(double v1, double v2, double v3,
                          double nx, double ny, double nz)
    {
        ::lightsOn();
        color c (v1,v2,v3);
        float fc [4]; c.toFloat(fc);
        int n = GL_LIGHT0 + ::lightCount;
        ::lightCount ++;
        float position[] = {-nx, -ny, -nz, 0};
        float ambient[] = {0,0,0,1};
        float direction[] = {nx,ny,nz};
        glLightfv (n, GL_DIFFUSE, fc);
        glLightfv (n, GL_AMBIENT, ambient);
        glLightfv (n, GL_SPECULAR, specular);
        glLightfv (n, GL_POSITION, position);
        glLightfv (n, GL_SPOT_DIRECTION, direction);
        glLightf (n, GL_SPOT_EXPONENT, 0);
        glLightf (n, GL_SPOT_CUTOFF, 180);
        glLightf (n, GL_LINEAR_ATTENUATION, linear);
        glLightf (n, GL_QUADRATIC_ATTENUATION, quadratic);
        glLightf (n, GL_CONSTANT_ATTENUATION, constant);
        glEnable (n);
    }

    /// Defines a new directional light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void pointLight(double  v1,double  v2,double  v3,double  x,double  y,double  z)
    {
        ::lightsOn();
        color c (v1,v2,v3);
        float fc [4]; c.toFloat(fc);
        int n = GL_LIGHT0 + ::lightCount;
        ::lightCount ++;
        float  position[] = {x, y, z, 1};
        float ambient[] = {0, 0, 0, 1};
        float direction[] = {0, 0, -1};
        glLightfv(n, GL_DIFFUSE, fc);
        glLightfv(n, GL_AMBIENT, ambient);
        glLightfv(n, GL_SPECULAR, specular);
        glLightfv(n, GL_POSITION, position);
        glLightfv(n, GL_SPOT_DIRECTION, direction);
        glLightf(n, GL_SPOT_EXPONENT, 0);
        glLightf(n, GL_SPOT_CUTOFF, 180);
        glLightf(n, GL_LINEAR_ATTENUATION, linear);
        glLightf(n, GL_QUADRATIC_ATTENUATION, quadratic);
        glLightf(n, GL_CONSTANT_ATTENUATION, constant);
        glEnable(n);
    }

    /// Defines a new ambient light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    void ambientLight(double  v1,double  v2,double  v3, double  x, double  y, double  z)
    {
        ::lightsOn();
        color c (v1,v2,v3);
        float fc [4]; c.toFloat(fc);
        int n = GL_LIGHT0 + ::lightCount;
        ::lightCount ++;
        float position[] = {x, y, z,0};
        float difuse[] = {0,0,0};
        float specular[] = {0,0,0};
        glLightfv(n, GL_DIFFUSE, difuse);
        glLightfv(n, GL_AMBIENT, fc);
        glLightfv(n, GL_SPECULAR, specular);
        glLightfv(n, GL_POSITION, position);
        glLightf(n, GL_LINEAR_ATTENUATION, linear);
        glLightf(n, GL_QUADRATIC_ATTENUATION, quadratic);
        glLightf(n, GL_CONSTANT_ATTENUATION, constant);
        glEnable(n);
    }


    /// Defines a new spot light.
    /// @arg v1, v2, v3: color components.
    /// @arg x, y, z: position coordinates.
    /// @arg nx, ny, nz: direction vector.
    /// @arg angle: angle in radians of spot aperture.
    /// @arg concentration: exponent which determines preference for spot axis.
    void spotLight(double v1, double  v2, double  v3,
                   double  x, double  y, double  z,
                   double  nx, double ny,double  nz,
                   double  angle, double  concentration)
    {
        ::lightsOn();
        color c (v1,v2,v3);
        float fc [4]; c.toFloat(fc);
        int n = GL_LIGHT0 + ::lightCount;
        ::lightCount ++;
        float position[] = {x, y, z,1};
        float direction[] = {nx, ny, nz};
        float ambient[] = {0,0,0};
        float specular[] = {0,0,0};
        glLightfv(n, GL_DIFFUSE, fc);
        glLightfv(n, GL_AMBIENT, ambient);
        glLightfv(n, GL_SPECULAR, specular);
        glLightfv(n, GL_POSITION, position);
        glLightfv(n, GL_SPOT_DIRECTION, direction);
        glLightf(n, GL_SPOT_EXPONENT, concentration);
        glLightf(n, GL_SPOT_CUTOFF, angle / 3.1416 * 180);
        glLightf(n, GL_LINEAR_ATTENUATION, linear);
        glLightf(n, GL_QUADRATIC_ATTENUATION, quadratic);
        glLightf(n, GL_CONSTANT_ATTENUATION, constant);
        glEnable(n);
    }

    /// Defines a specular coefficients of new light sources.
    /// @arg v1, v2, v3: color components.
    void lightSpecular (double v1,double  v2,double  v3)
    {
    	color c (v1,v2,v3);
    	c.toFloat(specular);
    }

    /// Defines light attenuation factors
    /// @args constant, linear, quadratic: coefficients of quadratic polynomial.
    void lightFalloff(double  constant,double  linear,double  quadratic)
    {
        ::constant = constant;
        ::linear = linear;
        ::quadratic = quadratic;
    }


    /// Turns on the default lighting
    void lights()
    {
        ::lightsOn();
        ::lightCount = 0;
        lightSpecular(0,0,0);
        lightFalloff(1, 0, 0);
        directionalLight(128, 128, 128, 0, 0, -1);
        ambientLight(128, 128, 128);
    }

    // Turns off the lights
    void noLights()
    {
        glDisable(GL_LIGHTING);
        for (int i = 0; i < ::lightCount; i++) glDisable(GL_LIGHT0+i);
        ::lights = false;
        ::lightCount = 0;
        ::constant = 1;
        ::linear = 0;
        ::quadratic = 0;
        ::specular[0] = 0;
        ::specular[1] = 0;
        ::specular[2] = 0;
        ::specular[3] = 1;
    }

}
