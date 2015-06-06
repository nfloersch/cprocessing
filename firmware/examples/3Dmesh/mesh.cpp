#include <cprocessing.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>
#include "mesh.hpp"

using namespace std;
using namespace cprocessing;

/// Load from a file in the ply format
void  Mesh::loadPly(const char filename[]) {

    // Open file for reading
    ifstream f (filename);
    
    // A buffer for one line
    char line [256];
    
    // How many vertices?
    int nvtx = 0;
    
    // How many faces? 
    int nface = 0;
    
    // Very simple parser. Reads a line and processes it according to state
    enum { HEADER, VERTEX, FACE } state = HEADER;
    
    // Reads until end of file
    while (!f.eof()) {
        
        // Read a line
        f.getline(line,255);
        string s(line);
        
        // What state?
        switch (state) {
            case HEADER: {
                // Look for some key elements of the header
                size_t found;
                if ((found = s.find("element vertex ")) != string::npos) {
                    istringstream iss (&line[found+15]);
                    iss >> nvtx;
                    cout << "vertices:" << nvtx << endl;
                }
                else if ((found = s.find("end_header")) != string::npos) {
                    state = VERTEX;
                    cout << "changed state to vertex\n";
                }
                break;
            }
            case VERTEX: {
                // Read one vertex
                istringstream iss (line);
                double x,y,z;
                iss >> x >> y >> z;
                vtx.push_back (PVector (x,y,z));
                
                // See if we are finished reading vertices
                nvtx--;
                if (nvtx == 0) {
                    state = FACE;
                    cout << "changed state to face\n";
                }
                
                break;
            }
            case FACE: {
                // Read one face
                istringstream iss (line);
                int n, i, j, k;
                iss >> n >> i >> j >> k;
                assert (n == 3); // Only triangle meshes are supported
                assert (i >= 0 && i < vtx.size()); 
                assert (j >= 0 && j < vtx.size()); 
                assert (k >= 0 && k < vtx.size()); 
                faceidx.push_back (i);
                faceidx.push_back (j);
                faceidx.push_back (k);

                break;
            } 
        }      
        
    } // While
    
}

/// Computes the bounding box, centroid, center, etc of the mesh
void Mesh::computeBounds () {
    
    // A sensible default for these attributes
    boxmin = boxmax = centroid = vtx[0];
    
    // Scan vertices to compute box bounds
    for (unsigned i = 1; i < vtx.size(); i++) {
        PVector p = vtx[i];
        centroid = centroid + p;
        
        if (p.x < boxmin.x) boxmin.x = p.x; 
        else if (p.x > boxmax.x) boxmax.x = p.x; 
        
        if (p.y < boxmin.y) boxmin.y = p.y; 
        else if (p.y > boxmax.y) boxmax.y = p.y; 
        
        if (p.z < boxmin.z) boxmin.z = p.z; 
        else if (p.z > boxmax.z) boxmax.z = p.z; 
    }
    
    // Other derived attributes
    boxcenter = (boxmin + boxmax) / 2;
    boxsize = boxmax - boxmin;
    centroid = centroid / vtx.size();
    
    // Compute the distance to the furthest point from the centroid
    radius = 0.0;
    for (unsigned i = 1; i < vtx.size(); i++) {
        radius = cprocessing::max(radius, vtx[i].dist(centroid));
    }
}


// Computes normals per face and per vertex
void Mesh::computeNormals() {

    // First reset face normals
    fnrm.clear();
    
    // Set all vertex normals as zero vectors and create a per vertex count array also filled with zeros
    vnrm.clear();
    vector<int>vcnt;
    for (unsigned i = 0; i < vtx.size(); i++) {
        vnrm.push_back(PVector());
        vcnt.push_back(0);
    }
    
    // Visit all faces
    for (unsigned iidx = 0; iidx < faceidx.size(); iidx+=3)  {
        // Get vertex indices
        int i = faceidx[iidx], j = faceidx[iidx+1], k = faceidx[iidx+2];
        
        // Compute face normal
        PVector normal = (vtx[j]-vtx[i]).cross(vtx[k]-vtx[j]);
        normal.normalize(); 
        fnrm.push_back(normal);
        
        // Accumulate normals per vertex
        vnrm [i] = vnrm [i] + normal; vcnt [i]++;
        vnrm [j] = vnrm [j] + normal; vcnt [j]++;
        vnrm [k] = vnrm [k] + normal; vcnt [k]++;
    }
    
    // Average vertex normals
    for (unsigned i = 0; i < vtx.size(); i++) {
        vnrm [i] = (vnrm[i] / vcnt[i]);
        vnrm [i].normalize();
    }   

}
