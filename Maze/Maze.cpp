#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

#include"Ball.h"
#include"Box.h"

using namespace sf;
using namespace std;

// Map of the maze
int lost[4][16] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1}
				 };

// Vector of boxes that will store the maze
vector<Box*> maze;

// Generates and stores maze data
void maze_gen(int dimX, int dimY, int(&map)[4][16], RenderWindow &window, float delta, float startX = 0.f, float startY = 0.f);

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
	
	// Generating the maze data
	maze_gen(4,16,lost,window,20,500.f,500.f);

	// Get the bounding boxes for the maze
	for (auto i = maze.begin(); i != maze.end(); i++)
	{
		(*i)->boundUpdate();
	}

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
		

		// Handling Collision
		for (auto i = maze.begin(); i != maze.end(); i++)
		{
			(*i)->isColliding(ball);
		}


		// Clear/Draw/Display Sequence
		window.clear(Color::Black);

		//<-Drawing code->
		ball.draw(window);
		for (auto i = maze.begin(); i != maze.end(); i++) // This loop draws the maze
		{
			(*i)->draw(window);
		}

		window.display();

	}


	return 0;
}

void maze_gen(int dimX, int dimY, int(&map)[4][16], RenderWindow& window, float delta, float startX, float startY)
{
	// Printing cursor coordinate
	float curX = startX;
	float curY = startY;
	// Reading the map
	for (int i = 0; i < dimX; i++)
	{
		for (int j = 0; j < dimY; j++)
		{
			// Checking for a box location in the map
			// If its a 1 (box location), create a Box object and draw it
			// else do nothing
			if (map[i][j])
			{
				// Create and store a box
				maze.push_back(new Box(20, 20, Color::Blue, curX, curY)); 				
			}
			else
			{

			}
			// Take cursor to next column
			curX+=delta;

		}
		// Take cursor to next row
		curY += delta;
		curX = startX;
	}

}