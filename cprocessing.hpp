/*
 * graphics.hpp
 *
 *  Created on: Apr 28, 2011
 *      Author: esperanc
 */

#ifndef CPROCESSING_HPP_
#define CPROCESSING_HPP_
#include <cmath>

namespace cprocessing {

	//
	// Global types
	//

	/// Used to test keys
	enum { CODED = 255, RETURN = '\r', ENTER = '\n',
		   ESC = 27, TAB = '\t', DELETE = 127
	};

	/// Other constants
	enum { F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
		   UP, DOWN, LEFT, RIGHT, CENTER, PAGEUP, PAGEDOWN, HOME, END, INSERT
	};

	/// Configuration flags
	enum {
		HALF_PIXEL_SHIFT = 1,    // Whether to shift vertex coordinates by half a pixel (true by default)
		Y_DOWN           = 1<<1  // Whether to flip the y axis so it points down, rather than up (true by default)
	};

	/// Shape constants
	typedef enum {
		POINTS, LINES, LINE_LOOP, LINE_STRIP, TRIANGLES,  TRIANGLE_STRIP, TRIANGLE_FAN, QUADS, QUAD_STRIP, POLYGON
	} ShapeMode;

	/// Parameter for the endShape function
	typedef enum {
		OPEN = 0, CLOSE = 1
	} ShapeClose;

	/// Color class
	struct color {
		unsigned char rgba[4];
		/// Constructor
		color (double r, double g, double b, double a = 255);
	};

	/// Represents a vector (or, sometimes, a point) in 3D
	class PVector {
	public:
		double x, y, z; ///< The coordinates
		/// Constructor
		PVector (double thex = 0, double they = 0, double thez = 0) : x(thex), y(they), z(thez) {}

		/// Assignment from coordinates
		void set (double thex = 0, double they = 0, double thez = 0) { x=thex; y=they; z=thez; }

		/// Assignment from another PVector
		void set (const PVector& other) { *this = other; }

		/// Assignment from an array of doubles
		void set (const double other[]) { x = other[0]; y = other[1]; z = other[2]; }

		/// Copy of the vector
		PVector get() { return *this; }

		/// Add
		PVector operator+(const PVector& other) const { return PVector(x+other.x, y+other.y, z+other.z); }
		PVector add (const PVector& other) const { return *this+other; }
		static PVector add (const PVector& a, const PVector& b) { return a+b; }

		/// Subtract
		PVector operator-(const PVector& other) const { return PVector(x-other.x, y-other.y, z-other.z); }
		PVector sub (const PVector& other) const { return *this-other; }
		static PVector sub (const PVector& a, const PVector& b) { return a-b; }

		/// Multiply by scalar
		PVector operator*(double s) const { return PVector(s*x, s*y, s*z); }
		PVector mult(double s) const { return *this*s; }
		static PVector mult(const PVector& v, double s)  { return v*s; }

		/// Divide by scalar
		PVector operator/(double s) const { return *this * (1/s); }
		PVector div(double s) const { return *this/s; }
		static PVector div(const PVector& v, double s)  { return v/s; }

		/// Dot product
		double dot (const PVector& other) const { return x*other.x + y*other.y + z*other.z; }
		static double dot (const PVector& a, const PVector& b) { return a.dot(b); }

		/// Cross product
		static PVector cross (const PVector& v1, const PVector& v2) {
			return PVector(v1.y * v2.z - v2.y * v1.z,
						v1.z * v2.x - v2.z * v1.x,
						v1.x * v2.y - v2.x * v1.y);
		}
		PVector cross (const PVector& other) const { return PVector::cross(*this,other); }

		/// Magnitude
		double mag () const { return sqrt(this->dot(*this)); }

		/// Distance between two points
		double dist (const PVector& other) const { return (this->sub(other)).mag(); }
		static double dist (const PVector& a, const PVector& b) { return a.dist(b); }

		/// Normalize (make unit length)
		void normalize() {
			double len = mag();
			if (len>1e-10)
			*this = *this / len;
		}

		/// Angle between two vectors
		static double angleBetween (const PVector& a, const PVector& b) {
			PVector acopy = a; acopy.normalize();
			PVector bcopy = b; bcopy.normalize();
			return acos(acopy.dot(bcopy));
		}

		/// Limit the magnitude of this vector to the value used for the max parameter
		void limit (double max) {
			double sz = this->mag();
			if (sz>max) *this = *this * (max / sz);
		}

		/// Returns vector coordinates as an array
		double* array() { return (double*) this; /* I KNOW this is unsafe! */ }
	};


	//
	// Global variables
	//
	extern int mouseX;  ///< Mouse x coordinate
	extern int mouseY;  ///< Mouse y coordinate
	extern int pmouseX; ///< Previous mouse x coordinate
	extern int pmouseY; ///< Previous mouse y coordinate
	extern bool mousePressed; ///< Whether any mouse button is pressed
	extern int mouseButton; ///< Which button is pressed
	extern bool keyPressed; ///< Whether a key was pressed
	extern unsigned char key; ///< Which (ASCII) key was pressed
	extern int keyCode; ///< Code for the last pressed key
	extern int width; ///< window width
	extern int height; ///< window height
	extern unsigned config; ///< configuration flags
	extern int frameRate; ///< Frames per second
	extern color strokeColor;  ///< Line drawing color
	extern color fillColor;   ///< Area drawing color

	//
	// Drawing Attributes
	//

	/// Sets line color
	void stroke (const color& c);

	inline void stroke (double r, double g, double b, double a = 255) {
		stroke (color (r,g,b,a));
	}

	inline void stroke (double gray, double a = 255) {
		stroke (color (gray,gray,gray,a));
	}

	inline void noStroke() {
		stroke (color(0,0,0,0));
	}

	/// Sets fill color
	void fill (const color & color);

	inline void fill (double r, double g, double b, double a = 255) {
		fill (color (r,g,b,a));
	}

	inline void fill (double gray, double a = 255) {
		fill (color (gray,gray,gray,a));
	}

	inline void noFill() {
		fill (color(0,0,0,0));
	}

	/// Sets line / point width
	void strokeWeight (int weight);

	/// Draws background with given color
	void background (const color&);

	inline void background (double r, double g, double b, double a = 255) {
		background (color (r,g,b,a));
	}

	inline void background (double gray, double a = 255) {
		background (color (gray,gray,gray,a));
	}

	// Line smoothing
	void smooth(); ///< Turns on smoothing

	void noSmooth(); ///< Turns off smoothing

	//
	// Drawing Primitives
	//

	/// Draws a 3D line segment given the coordinates
	/// of its endpoints.
	/// @param x0 The x coordinate of the first endpoint
	/// @param y0 The y coordinate of the first endpoint
	/// @param z0 The z coordinate of the first endpoint
	/// @param x1 The x coordinate of the second endpoint
	/// @param y1 The y coordinate of the second endpoint
	/// @param z1 The z coordinate of the second endpoint
	void line (double x0, double y0, double z0,
			   double x1, double y1, double z1);

	/// Draws a 2D line segment given the coordinates
	/// of its endpoints.
	/// @param x0 The x coordinate of the first endpoint
	/// @param y0 The y coordinate of the first endpoint
	/// @param x1 The x coordinate of the second endpoint
	/// @param y1 The y coordinate of the second endpoint
	inline void line (double x0, double y0, double x1, double y1) {
		line (x0, y0, 0, x1, y1, 0);
	}

	/// Draws a filled 3D triangle given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
    /// @param y0 The y coordinate of the first vertex
    /// @param z0 The z coordinate of the first vertex
    /// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
    /// @param z1 The z coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
    /// @param y2 The y coordinate of the third vertex
    /// @param z2 The z coordinate of the third vertex
    void triangle (double x0, double y0, double z0,
    		       double x1, double y1, double z1,
    			   double x2, double y2, double z2) ;

	/// Draws a filled 2D triangle given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
	/// @param y0 The y coordinate of the first vertex
	/// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
	/// @param y2 The y coordinate of the third vertex
    inline void triangle (double x0, double y0,
    		              double x1, double y1,
    			          double x2, double y2) {
    	triangle (x0, y0, 0, x1, y1, 0, x2, y2, 0);
    }

    /// Draws a filled 2D quadrilateral given the coordinates
	/// of its vertices.
	/// @param x0 The x coordinate of the first vertex
	/// @param y0 The y coordinate of the first vertex
	/// @param x1 The x coordinate of the second vertex
	/// @param y1 The y coordinate of the second vertex
	/// @param x2 The x coordinate of the third vertex
	/// @param y2 The y coordinate of the third vertex
	/// @param x3 The x coordinate of the third vertex
	/// @param y3 The y coordinate of the third vertex
     void quad (double x0, double y0,
    		    double x1, double y1,
    	        double x2, double y2,
    	        double x3, double y3);


    /// Draws a point.
	/// @param x The x coordinate of the point
	/// @param y The y coordinate of the point
	/// @param z The z coordinate of the point
	void point (double x, double y, double z = 0);


	//
	// Shapes and vertices
	//

	// Starts the definition of a shape
	void beginShape(ShapeMode mode = POLYGON);

	// Finishes and renders the shape
	void endShape(ShapeClose close = OPEN);

	// Adds a vertex to the shape
	void vertex (double x, double y, double z=0);

	// Specifies a normal for the next vertices
	void normal (double x, double y, double z);

    /// Establishes the Bézier level of detail, i.e., the number of points
    /// per Bézier curve segment.
	void bezierDetail(int n);

    /// Given the x or y coordinate of Bézier control points a,b,c,d and
    /// the value of the t parameter, return the corresponding
    /// coordinate of the point.
	double bezierPoint (double a, double b, double c, double d,double t);

	/// Given the x or y coordinate of Bézier control points a,b,c,d and
	/// the value of the t parameter, return the corresponding
	/// coordinate of the tangent at that point."""
	double bezierTangent (double a,double b,double c,double d,double t);

    /// Generates a cubic bezier arc. Arguments are of the form
    /// (cx1, cy1, cx2, cy2, x, y), i.e. coordinates
    /// for 3 control points in 2D. The first control point of the
    /// arc is the last point of the previous arc or the last vertex.
	void bezierVertex(double cx1,double cy1,double cz1,double cx2,double cy2,double cz2,double x,double y,double z);

	/// 2D version of bezierVertex
	inline void bezierVertex(double cx1,double cy1,double cx2,double cy2,double x,double y) {
		bezierVertex (cx1, cy1, 0, cx2, cy2, 0, x, y, 0);
	}


	//
	// Transformations
	//

    /// Applies a translation transformation
    void translate (double dx, double dy, double dz);

    /// Applies a scale transformation
    void scale (double dx, double dy, double dz);

    /// Applies a uniform scale
    inline void scale (double factor) { scale (factor, factor, factor); }

    /// Applies a rotation transformation
    void rotate (double degrees, double axisx, double axisy, double axisz);

    /// Resets the transformation to none
    void resetMatrix();

    /// Fills matrix with the current transformation matrix
    void getMatrix (double matrix [16]);

    /// Multiplies given matrix by current transformation matrix
    void applyMatrix (double matrix [16]);

    /// Duplicates the top of the matrix stack
    void pushMatrix();

    /// Discards the top of the matrix stack
    void popMatrix();

    ///	Creates a viewing transformation given the camera position
	///	(eyex,eyey,eyez), the center of the scene (centerx, centery, centerz) and
	///	a vector to be used as the up direction (upx, upy, upz). If no args
	///	are passed, the standard camera is created.
	void camera (double eyeX, double eyeY, double eyeZ,
				 double centerX, double centerY, double centerZ,
				 double upX, double upY, double upZ);
	void camera ();

	/// Loads a perspective projection matrix, where
	/// fov is the field-of-view angle (in radians) for vertical direction, aspect
	/// is the ratio of width to height, znear is the z-position of nearest clipping
	/// plane and zfar is the z-position of nearest farthest plane. If no args are
	/// passed, the standard projection is created, i.e, equivalent to
	/// perspective(PI/3.0, width/height, cameraZ/10.0, cameraZ*10.0)
	/// where cameraZ is ((height/2.0) / tan(PI*60.0/360.0))
	void perspective(double fov, double aspect, double znear, double zfar);

	void perspective ();

	///	Loads an orthogonal projection matrix.
	///	The clipping volume in this case is an axes-aligned parallelepiped, where
	///	left and right are the minimum and maximum x values, top and bottom are
	///	the minimum and maximum y values, and near and far are the minimum and
	///	maximum z values. If no parameters are given, the default is used:
	///	ortho(0, width, 0, height, -height*2, height*2).
	void ortho(double left, double right, double bottom, double top, double near, double far);

	void ortho ();


    /// Returns the projected space coordinates of object coordinates ox,oy,oz
	void screenXYZ (double ox, double oy, double oz,
					double& sx, double& sy, double& sz);

	inline double screenX (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpx;
	}

	inline double screenY (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpy;
	}

	inline double screenZ (double ox, double oy, double oz) {
		double tmpx, tmpy, tmpz;
		screenXYZ (ox, oy, oz, tmpx, tmpy, tmpz);
		return tmpz;
	}


    //
	// Initialization
	//

    /// Sets up a window of the given size
    /// @param width Desired window width in pixels.
    /// @param height Desired window height in pixels.
    /// @param name Desired window title.
    void size (unsigned width, unsigned height, const char* name = "Graphics");

    /// Run the drawing application
    void run();
}

#endif /* CPROCESSING_HPP_ */
