#include<SFML/Graphics.hpp>
#include<iostream>
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
	const float radius = 25.f;
	CircleShape ball(radius);
	ball.setFillColor(Color::Red);
	ball.setPosition(200.f,500.f);
	const float velocity = 0.5f; // distance ball moves per keypress



	// Creating collision object
	RectangleShape wall(Vector2f(100.f,400.f));
	wall.setFillColor(Color::Blue);
	wall.setPosition(1000.f,500.f);

	// Game loop
	while (window.isOpen())
	{

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			ball.move(velocity,0.f);
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


		// Getting bounding box for the ball and the wall
		FloatRect ball_bound = ball.getGlobalBounds();
		FloatRect wall_bound = wall.getGlobalBounds();


		// Implementing collision between ball and wall. This is done by checking collision
		// and the direction of ball movement. When a collision happens, velocity
		// is applied in the opposite direction of the movement that caused the collision.		
		if (ball_bound.intersects(wall_bound) && Keyboard::isKeyPressed(Keyboard::Down))
		{
			ball.move(0.f,-velocity);
		}

		if (ball_bound.intersects(wall_bound) && Keyboard::isKeyPressed(Keyboard::Up))
		{
			ball.move(0.f, velocity);
		}

		if (ball_bound.intersects(wall_bound) && Keyboard::isKeyPressed(Keyboard::Left))
		{
			ball.move(velocity,0.f);
		}

		if (ball_bound.intersects(wall_bound) && Keyboard::isKeyPressed(Keyboard::Right))
		{
			ball.move(-velocity,0.f);
		}


		// Making ball stay in window
		if (ball.getPosition().y == winY- 2*radius && Keyboard::isKeyPressed(Keyboard::Down))
		{
			ball.move(0.f, -velocity);
		}

		if (ball.getPosition().y == 0  && Keyboard::isKeyPressed(Keyboard::Up))
		{
			ball.move(0.f, velocity);
		}

		if (ball.getPosition().x == 0 && Keyboard::isKeyPressed(Keyboard::Left))
		{
			ball.move(velocity,0.f);
		}

		if (ball.getPosition().x == winX - 2 * radius && Keyboard::isKeyPressed(Keyboard::Right))
		{
			ball.move(-velocity,0.f);
		}



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
		window.draw(ball);
		window.draw(wall);

		window.display();

	}


	return 0;
}