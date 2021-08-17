// Box class. Used to create the maze.
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

#include"Ball.h"

using namespace sf;


class Box
{
private:
	float dimX; // Dimesions of the box
	float dimY;
	Color color; // Color of the box
	RectangleShape box; // The RectangleShape object used as the box
	float X;  // Position of the box
	float Y;

public:

	// Bounding box of the box
	FloatRect box_bound;

	// Zero-argument constructor
	// DO NOT USE
	Box();

	// Sets the values for all the data members
	Box(float dX, float dY, Color col, float x, float y);

	// Draw the ball on the screen
	void draw(RenderWindow& window);

	// Detect collision with ball
	void isColliding(Ball &ball);

	// Update the bouding box
	void boundUpdate();
};

