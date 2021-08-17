// Ball class. The main character of the maze game.
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

using namespace sf;

class Ball
{
private:
	float radius; // Radius of the ball
	float startX = 0.f; // Starting coordinates of the ball. Default values zero
	float startY = 0.f;
	Color color; // Color of the ball	

	CircleShape ball; // The CircleShape object used as the ball

public:

	// Amount by which the ball moves per keypress
	float velocity; 

	// Bounding box of the ball
	FloatRect ball_bound;

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

	// Update the bouding box
	void boundUpdate();

	// Makes the ball move X units along x-direction and Y units along y-direction
	void move(float x, float y);
};

