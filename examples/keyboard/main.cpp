/*
 * main.cpp
 *
 *  Created on: July 27, 2012
 *      Author: Claudio esperanca
 */

#include <cprocessing.hpp>
#include <iostream>
using namespace cprocessing;

void keyPressed () {
	if (key == CODED) {
		std::cout << "CODED:" << keyCode << "\n";
		if (keyCode == F1) {
			cursor (MOVE);
		}
		else if (keyCode == F2) {
			cursor (CROSS);
		}
	} else {
		std::cout << "key = " << key << "\n";
	}
}

void keyReleased () {
	cursor (ARROW);
}

void draw() {
	background (255);
}