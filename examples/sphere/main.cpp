#include <cprocessing.hpp>

using namespace cprocessing;

void draw () {
	background(200);
	//noStroke();
	lights();
	translate(150, 150, 0);
	sphere(100);
}

void setup() {
	size (300,300);
}

