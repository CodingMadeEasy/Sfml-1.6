// C++ Sfml Made Easy Tutorial 24 - Vector2 Class
// CodingMadeEasy

#include<SFML/Graphics.hpp>
#include<iostream>

#define ScreenWidth 800
#define ScreenHeight 600

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML - CodingMadeEasy");

    sf::Vector2f fontPosition (ScreenWidth / 2, ScreenHeight / 2);

    sf::Font gameFont;
    gameFont.LoadFromFile("Blade 2.ttf", 100);

    sf::String gameText("CodingMadeEasy", gameFont, 100);
    gameText.SetColor(sf::Color(44, 117, 255));
    sf::FloatRect textRect = gameText.GetRect();

    gameText.SetCenter(textRect.GetWidth() / 2, textRect.GetHeight() / 2);

    gameText.SetPosition(fontPosition);

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        Window.Clear();
        Window.Draw(gameText);
        Window.Display();
    }
    return 0;
}
