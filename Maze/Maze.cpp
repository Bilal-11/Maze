#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;


int main()
{
	// Instantiate the window
	RenderWindow window(VideoMode(1400,1200),"Maze",Style::Titlebar|Style::Close);

	// Instantiating and Loading font
	Font font;
	if (!font.loadFromFile("GrandHotel-Regular.otf"))
	{
		//---TODO: error code---		
	}

	Text text;
	//---TODO?: Can write a function to do all the things listed below---
	text.setFont(font);
	text.setString("Bilal");
	text.setCharacterSize(480);
	text.setFillColor(Color::Green);

	// Game loop
	while (window.isOpen())
	{
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
		window.draw(text);

		window.display();

	}


	return 0;
}