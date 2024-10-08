
#include "mover.h"
#include <iostream>

// Mover Constructor
Mover::Mover(glm::vec2 position, float mass) : position(position), mass(mass), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), radius(mass * 5), mu(0.01f) {}

// Adding acceleration to velocity, then adding the velocity to the position, then reset the acceleration
void Mover::update() {
	// Acceleration changes velocity
	velocity += acceleration;

	// Velocity changes position
	position += velocity;

	// Reset acceleration each update
	acceleration = glm::vec2(0.0f, 0.0f);
}

// Apply given force (wind + friction) and add it to acceleration
void Mover::applyForce(glm::vec2 force) {
	glm::vec2 scaledForce = force / mass;
	acceleration += scaledForce;
}

// Applying friction to self (mover)
void Mover::friction() {
	// Get direction of friction (opposite of velocity, normalized)
	glm::vec2 friction = glm::normalize(velocity) * -1;

	// Magnitude of friction
	float normal = mass;

	// Simplified by ignoring gravity constant
	friction = glm::normalize(friction) * (mu * normal);

	// Apply friction as a force
	applyForce(friction);
}

// NEEDS EDGES FUNCTION

// Display a mover ball with white transparent fill and thin boarder
void Mover::display() {
	ofSetColor(255, 200);
	ofSetLineWidth(2);

	ofDrawEllipse(position.x, position.y, radius * 2, radius
		* 2);
}

// Debugging mover to see its position and mass with console output
void Mover::debug() {
	std::cout << "position: (" << position << ") ";
	std::cout << "mass: " << mass << "\n";
}