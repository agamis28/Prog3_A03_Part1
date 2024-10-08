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
	Mover(glm::vec2, float); // Constructor

	void update();
	void applyForce(glm::vec2);
	void friction();
	void display();
	void debug();
};

