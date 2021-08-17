// Ball class. The main character of the maze game.
#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
	float radius; // Radius of the ball
	float startX = 0.f; // Starting coordinates of the ball. Default values zero
	float startY = 0.f;
	Color color; // Color of the ball
	float velocity; // Amount by which the ball moves per keypress

	CircleShape ball; // The CircleShape object used as the ball

public:
	// Zero-argument constructor
	// DO NOT USE
	Ball();

	// The constructor to be used. Sets the values for all the data members
	// Default values for startX and startY are 0.f
	Ball(float rad, Color col, float vel, float stX, float stY);

	// Move the ball using arrow keys. velocity is the number of units moved per keypress.
	void movement();

	// Making ball stay in window of size winX x winY
	void winBound(float winX, float winY);

	// Draw the ball on the screen
	void draw(RenderWindow &window);
};

