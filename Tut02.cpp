// C++ SFML MADE EASY TUTORIAL 2 - EVENTS
// CODINGMADEEASY [SFML 1.6]

#include<SFML/Graphics.hpp> 

int main()
{
	sf::RenderWindow Screen (sf::VideoMode (800, 600, 32), "SFML Made Easy");
	
	while(Screen.IsOpened())
	{
		sf::Event Event; 
		while(Screen.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed || Event.Key.code == sf::Key::Escape)
				Screen.Close();
		}
	}
	
	Screen.Display(); 
	
	return 0;
}