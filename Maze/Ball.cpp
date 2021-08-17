#include "Ball.h"

// Zero-argument constructor.
// DO NOT USE
Ball::Ball()
{
	//---TODO: error code---
}

// The constructor to be used. Sets the values for all the data members
// Default values for startX and startY are 0.f
Ball::Ball(float rad, Color col, float vel, float stX, float stY)
{
	// Set values for data members
	radius = rad;
	color = col;
	velocity = vel;
	startX = stX;
	startY = stY;

	// Set radius of the ball
	ball.setRadius(radius);

	// Set color of ball and starting position
	ball.setFillColor(color);
	ball.setPosition(startX, startY);
}

// Move the ball using arrow keys. velocity is the number of units moved per keypress. 
void Ball::movement()
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		ball.move(velocity, 0.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		ball.move(-velocity, 0.f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		ball.move(0.f, -velocity);
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		ball.move(0.f, velocity);
	}
}

// Making ball stay in window of size winX x winY
void Ball::winBound(float winX, float winY)
{
	// Making ball stay in window
	if (ball.getPosition().y == winY - 2 * radius && Keyboard::isKeyPressed(Keyboard::Down))
	{
		ball.move(0.f, -velocity);
	}

	if (ball.getPosition().y == 0 && Keyboard::isKeyPressed(Keyboard::Up))
	{
		ball.move(0.f, velocity);
	}

	if (ball.getPosition().x == 0 && Keyboard::isKeyPressed(Keyboard::Left))
	{
		ball.move(velocity, 0.f);
	}

	if (ball.getPosition().x == winX - 2 * radius && Keyboard::isKeyPressed(Keyboard::Right))
	{
		ball.move(-velocity, 0.f);
	}
}

// Draw the ball on the screen
void Ball::draw(RenderWindow &window)
{
	window.draw(ball);
}