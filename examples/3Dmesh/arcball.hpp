#include <cprocessing.hpp>

//
// A very simple implementation of an arcball
//
class Arcball {
    
public: 
    double matrix [16]; // Where the rotation transformation is stored
    PVector center;     // Where the center of the arcball is defined (in window coordinates)
    double radius;      // Arcball radius in pixels
    
    // Constructor given the center of the arcball and the radius
    Arcball (double x, double y, double r) {
    
        // Store center and radius
        center = PVector (x, y, 0);
        radius = r;
        
        // Identity matrix
        for (int i = 0; i < 16; i++) matrix [i] = (i % 4) == (i / 4) ? 1 : 0;
    }  
    
    // Apply mouse drag interaction to matrix. 
    // Interaction is dragging from point (x0, y0) to (x1, y1)
    inline void drag(double x0, double y0, double x1, double y1) {
    
       // Use coordinates relative to the center of the arcball
       PVector src(x0-center.x, y0-center.y, 0);
       PVector dst(x1-center.x, y1-center.y, 0);
       
       // Consider coordinates relative to unit circle. Project onto circle if needed
       double smag = src.mag(); 
       src.normalize();
       if (smag < radius) src = src * (smag/radius);
       double dmag = dst.mag();
       dst.normalize();
       if (dmag < radius) dst = dst * (dmag/radius);
       
       // Bail out if src == dst
       if ((src-dst).mag() < 1e-6) return;

       // Obtain z on the unit sphere
       src.z = sqrt(1.0000001 - src.mag());
       dst.z = sqrt(1.0000001 - dst.mag());
       
       // Compute axis and angle
       PVector axis = src.cross(dst);
       double angle = asin(axis.mag());
       
//       std::cout<<"Axis:" << axis.x <<"," << axis.y << "," << axis.z <<"\n";
//       std::cout<<"src:" << src.x <<"," << src.y << "," << src.z <<"\n";
//       std::cout<<"dst:" << dst.x <<"," << dst.y << "," << dst.z <<"\n";
//       std::cout<<"Angle:" << angle << "\n";              
       
       // postmultiply rotation with current matrix
       pushMatrix();
       resetMatrix();
       rotate(angle, axis.x, axis.y, axis.z);
       applyMatrix(matrix);
       getMatrix(matrix);
       popMatrix();
       
       
//       for (int i = 0; i < 16; i++) {
//            std:: cout << matrix [i] << "\t"; 
//            if (i % 4 == 3) std::cout << "\n";
//       }
    }
    
};
