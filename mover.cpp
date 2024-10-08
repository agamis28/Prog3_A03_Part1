
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

void Mover::debug() {
	std::cout << "position: (" << position << ") ";
	std::cout << "mass: " << mass << "\n";
}