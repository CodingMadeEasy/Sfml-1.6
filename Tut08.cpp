// C++ SFML MADE EASY TUTORIAL 5~6 - SHAPES 
// CODINGMADEEASY [SFML 1.6]

#include<SFML/Graphics.hpp> 

int main()
{
	sf::RenderWindow Window(sf::VideoMode (800, 600, 32), "SFML Made Easy");
	
	sf::Shape Rect = sf::Shape::Rectangle(0, 0, 10, 10, sf::Color::Red);
	
	while(Screen.IsOpened())
	{
		sf::Event Event; 
		while(Screen.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed || Event.Key.code == sf::Key::Escape)
				Screen.Close();
		}
	}
	
	if(Window.GetInput().IsKeyDown(sf::Key::Right))
		Rect.Move (5.0f. 0.0f);
	else if (Window.GetInput().IsKeyDown(sf::Key::Left))
		Rect.Move (-5.0f, 0.0f);
	else if(Window.GetInput().IsKeyDown(sf::Key::Up))
		Rect.Move(0.0f, -5.0f);
	else if(Window.GetInput().IsKeyDown(sf::Key::Down))
		Rect.Move(0.0f, 5.0f);
	
	Window.Clear(); 
	Winow.Draw(Rect);
	Window.Display(Rect);
	
	Screen.Display(); 
	
	return 0;
}