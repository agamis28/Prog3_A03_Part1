#pragma once

#include "ofMain.h"

class Mover
{
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;
	float mass;
	float radius;
	float mu;

public:
	Mover(glm::vec2 position, float mass); // Constructor

	void update();
	void debug();
};

