#include<SFML/Graphics.hpp>
#include<iostream>
#include"Ball.h"
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
		//---TODO: error code---		
	}

	// Creating player character (ball)
	Ball ball(25.f,Color::Red,0.5f,200.f,500.f);	

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



		// Clear/Draw/Display Sequence
		window.clear(Color::Black);

		//<-Drawing code->
		ball.draw(window);
		

		window.display();

	}


	return 0;
}