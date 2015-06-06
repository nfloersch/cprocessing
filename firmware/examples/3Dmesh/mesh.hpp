#ifndef __MESH_HPP
#define __MESH_HPP

#include <vector>
#include <cprocessing.hpp>

///
/// Represents a triangular mesh
///
struct Mesh {

	std::vector<cprocessing::PVector> vtx;  ///< An array of vertices
	std::vector<cprocessing::PVector> vnrm;  ///< Normals for the vertices
	std::vector<cprocessing::PVector> fnrm;  ///< Face normals
	std::vector<int> faceidx; ///< Contains vtx indices. Each 3 indices form a triangle
	
	cprocessing::PVector boxmin, boxmax; // Minimum and maximum coordinate of the bounding box
	cprocessing::PVector centroid; // Centroid of the mesh
	cprocessing::PVector boxcenter;  // Center of the bounding box 
	cprocessing::PVector boxsize; // Size of the bounding box
	double radius; // Radius of the mesh
	
	/// Builds an empty mesh
	Mesh () {};
	
	/// Load from a file in the ply format
	void loadPly(const char filename[]);
	
	/// Computes the bounding box, centroid, center, etc of the mesh
	void computeBounds ();
	
	/// Estimates the normals of the mesh
	void computeNormals ();
	
};

#endif
