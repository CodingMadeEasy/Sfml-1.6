// C++ SFML MADE EASY TUTORIAL 5~6 - SHAPES 
// CODINGMADEEASY [SFML 1.6]

#include<SFML/Graphics.hpp> 

int main()
{
	sf::RenderWindow Screen (sf::VideoMode (800, 600, 32), "SFML Made Easy");
	
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
	
	Screen.Clear(); 
	Screen.Display(Rect);
	
	Screen.Display(); 
	
	return 0;
}