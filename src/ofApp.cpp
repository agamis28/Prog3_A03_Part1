#include "ofApp.h"
#include <iostream>

glm::vec2 centerOfScreen;
glm::vec2 mouse;
glm::vec2 wind;

//--------------------------------------------------------------
void ofApp::setup() {
	// Setting amount of movers spawned in
	moversAmount = 10;
	// Setting rand seed
	srand(time(0));
	// Spawning randomized movers
	randomizeMovers();

	// Debugging movers stats
	for (int i = 0; i < moversAmount; i++) {
		std::cout << "mover #" << i << ": ";
		movers[i].debug();
	}

	// Setting up background color
	ofBackground(60, 179, 113);
}

//--------------------------------------------------------------
void ofApp::update() {

	// Get position vector of center of screen
	centerOfScreen = glm::vec2((ofGetWidth() / 2), (ofGetHeight() / 2));

	// Updating movers
	for (int i = 0; i < moversAmount; i++) {

		// Updating movers for any applying wind when mouse is being pressed
		if (ofGetMousePressed()) {
			mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());

			// Debug Mouse Pressed and Location Pressed
			//std::cout << "*Mouse Pressed*\nMouse location: (" << mouse << ")\n";

			// Find direction opposite of mouse, normalize and set mag to 0.5 to get wind vector
			wind = glm::normalize(centerOfScreen - mouse) * 0.5f;

			// Apply wind force to each mover when mouse is pressed
			movers[i].applyForce(wind);
		}

		// Update, frication and check edges for all movers
		movers[i].friction();
		movers[i].update();
		movers[i].edges();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofSetColor(0, 0, 0);

	// Displaying FPS
	string fps = "FPS: " + ofToString(std::round(ofGetFrameRate() * 100) / 100);
	ofDrawBitmapString(fps, 5, 15);

	// Displaying movers
	for (int i = 0; i < moversAmount; i++) {
		movers[i].display();
	}

	// Draw arrow when mouse is being pressed
	if (ofGetMousePressed()) {
		drawArrow(centerOfScreen, wind * 250, 20);
	}
}

//--------------------------------------------------------------
// Creating moversAmount of movers in random positions and masses
void ofApp::randomizeMovers() {
	// Loop through movers amount and create movers
	for (int i = 0; i < moversAmount; i++) {
		// Get a random position vector
		glm::vec2 randomPosition = glm::vec2((1 + rand() % (ofGetWidth())), (1 + rand() % (ofGetHeight())));
		// Get a random mass
		float randomMass = 1 + rand() % 8;

		// Create a new mover and put it on the end of the movers array
		movers.emplace_back(Mover(randomPosition, randomMass));
	}
}

//--------------------------------------------------------------
// Creating moversAmount of movers in random positions and masses
void ofApp::drawArrow(glm::vec2 arrowBase, glm::vec2 arrowEnd, float arrowSize) {

	// Save current style settings & transformations
	ofPushMatrix();

	// Copy the vector and limit it's length to 
	// account for the addition of the arrow head.
	glm::vec2 drawVector = arrowEnd;
	drawVector = glm::normalize(drawVector) * (glm::length(arrowEnd) - arrowSize);

	// Set color and line thickness
	ofSetColor(0, 191, 255);
	ofSetLineWidth(arrowSize / 5);

	// Move the 0,0 location to the base of the vector.
	ofTranslate(arrowBase.x, arrowBase.y);

	// Draw the vector line
	ofDrawLine(0, 0, drawVector.x, drawVector.y);

	// Rotate to point in the direction of the vector
	float angle = atan2(drawVector.y, drawVector.x);
	ofRotateDeg(ofRadToDeg(angle));

	// Move the 0,0 location to the start of the arrow head
	ofTranslate(glm::length(drawVector), 0);

	// Draw the arrow head such that it points to the vector tip
	ofSetColor(0, 191, 255);
	ofBeginShape();
	ofVertex(0, arrowSize / 2);
	ofVertex(0, -arrowSize / 2);
	ofVertex(arrowSize, 0);
	ofEndShape();

	// Restore style settings & transformations
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
