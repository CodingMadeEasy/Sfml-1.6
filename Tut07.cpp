// C++ SFML MADE EASY TUTORIAL 7 - LOADING & DISPLAYING IMAGES
// CODINGMADEEASY [SFML 1.6]

#include<SFML/Graphics.hpp> 

int main()
{
	sf::RenderWindow Screen (sf::VideoMode (800, 600, 32), "SFML Made Easy");
	
	sf::Image Image; 
	sf::Sprite Sprite; 
	
	if(!Image.LoadFromFile("Image.png"))
		std::cout << "Could not load the image file" << std::endl; 
	
	Sprite.SetImage(Image);
	
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
	Screen.Draw(Sprite);
	Screen.Display(); 
	
	return 0;
}