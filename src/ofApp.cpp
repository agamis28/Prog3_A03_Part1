#include "ofApp.h"
#include <iostream>

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
	// Updating movers
	for (int i = 0; i < moversAmount; i++) {

		// Updating movers for any applying wind
		if (ofGetMousePressed()) {
			glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());

			// Debug Mouse Pressed and Location Pressed
			//std::cout << "*Mouse Pressed*\nMouse location: (" << mouse << ")\n";

			glm::vec2 centerOfScreen = glm::vec2((ofGetWidth() / 2), (ofGetHeight() / 2));
			glm::vec2 wind = centerOfScreen - mouse;

			movers[i].applyForce(wind);
		}

		movers[i].friction();
		movers[i].update();
		movers[i].edges();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	// Displaying FPS
	string fps = "FPS: " + ofToString(std::round(ofGetFrameRate() * 100) / 100);
	ofDrawBitmapString(fps, 5, 15);

	// Displaying movers
	for (int i = 0; i < moversAmount; i++) {
		movers[i].display();
	}
}

//--------------------------------------------------------------
// Creating moversAmount of movers in random positions and masses
void ofApp::randomizeMovers() {
	for (int i = 0; i < moversAmount; i++) {
		glm::vec2 randomPosition = glm::vec2((1 + rand() % (ofGetWidth())), (1 + rand() % (ofGetHeight())));
		float randomMass = 1 + rand() % 8;
		movers.emplace_back(Mover(randomPosition, randomMass));
	}
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
