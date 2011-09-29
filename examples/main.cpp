#include <cprocessing.hpp>

using namespace cprocessing;

void setup(){
	size(200,200);
}

void draw(){
	//Top left rectangle
	rectMode(CORNER);
	rect(10,10,40,40);

	//The second rectangle, slightly overlapping the first
	rectMode(CENTER);
	rect(40,40, 40, 40);

	//The third rectangle, in the middle of the screen.
	rectMode(RADIUS);
	rect(100,100, 20 ,20);

	//The last rectangle
	rectMode(CORNERS);
	rect(140, 140, 180, 180);
}
