#include "Box.h"

// Zero-argument constructor
// DO NOT USE
Box::Box()
{
	std::cout << std::endl << "Error: Don't use this constructor for Box.";
	exit(2);
}

// Sets the values for all the data members
Box::Box(float dX, float dY, Color col, float x, float y)
{
	// Set values of data members
	dimX = dX;
	dimY = dY;
	color = col;
	X = x;
	Y = y;
	
	// Set the dimensions of the box
	box.setSize(Vector2f(dimX, dimY));

	// Set color of the box
	box.setFillColor(color);
	
	// Set position of the box
	box.setPosition(X,Y);
}

// Draw the ball on the screen
void Box::draw(RenderWindow& window)
{
	window.draw(box);
}

// Detect collision with ball
void Box::isColliding(Ball& ball)
{
	// Implementing collision between the ball and the box. This is done by checking collision
	// and the direction of ball movement. When a collision happens, velocity
	// is applied in the opposite direction of the movement that caused the collision.
	if (ball.ball_bound.intersects(box_bound) && Keyboard::isKeyPressed(Keyboard::Down))
	{
		ball.move(0.f, -ball.velocity);
	}

	if (ball.ball_bound.intersects(box_bound) && Keyboard::isKeyPressed(Keyboard::Up))
	{
		ball.move(0.f, ball.velocity);
	}

	if (ball.ball_bound.intersects(box_bound) && Keyboard::isKeyPressed(Keyboard::Left))
	{
		ball.move(ball.velocity, 0.f);
	}

	if (ball.ball_bound.intersects(box_bound) && Keyboard::isKeyPressed(Keyboard::Right))
	{
		ball.move(-ball.velocity, 0.f);
	}
}

// Update the bouding box
void Box::boundUpdate()
{
	box_bound = box.getGlobalBounds();
}