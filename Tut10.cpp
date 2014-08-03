#include<iostream> 
#include<SFML/Graphics.hpp> 

int main()
{
	sf::Clock Clock; 
	
	sf::RenderWindow Window (sf::VideoMode(800, 600, 32), "SFML MADE EASY"); 
	
	while(Window.IsOpened())
	{
		float time = Window.GetFrameTime(); 
		std::cout << time << std::endl;
	}
	return 0;
}