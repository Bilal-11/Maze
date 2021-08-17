#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

#include"Ball.h"
#include"Box.h"

using namespace sf;
using namespace std;


int main()
{
	// Instantiate the window
	const int winX = 1400; // window's x and y dimensions
	const int winY = 1200;
	RenderWindow window(VideoMode(winX,winY),"Maze",Style::Titlebar|Style::Close);

	// Instantiating and Loading font
	Font font;
	if (!font.loadFromFile("GrandHotel-Regular.otf"))
	{
		cout << endl << "Error in Loading Font";
		exit(1);
	}

	// Creating player character (ball)
	Ball ball(25.f,Color::Red,0.5f,200.f,500.f);

	//
	Box box(20.f,20.f,Color::Blue,800.f,200.f);

	// Game loop
	while (window.isOpen())
	{

		// Move the ball using arrow keys
		ball.movement();

		// Making ball stay in window
		ball.winBound(winX, winY);		
		

		Event event;

		// Event loop
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		// Update bounding boxes
		ball.boundUpdate();
		box.boundUpdate();

		// Handling Collision
		box.isColliding(ball);


		// Clear/Draw/Display Sequence
		window.clear(Color::Black);

		//<-Drawing code->
		ball.draw(window);
		box.draw(window);

		window.display();

	}


	return 0;
}