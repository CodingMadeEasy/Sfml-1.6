// // C++ SFML TUTORIAL 9 - SPRITE ANIMATION [PART 1]
// CODINGMADEEASY (PETER HENRY) - MADE WITH SFML 1.6
// TAG: SPRITESHEET

#include <iostream>
#include <SFML/Graphics.hpp>

#define ScreenWidth 800
#define ScreenHeight 600

#define sDown 0
#define sLeft 48
#define sRight 96
#define sUp 144

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "CodingMadeEasy Tutorials");

    sf::Image tempImage;
    sf::Sprite playerSprte;
    

    if(tempImage.LoadFromFile("Player.png"))
        playerSprte.SetImage(tempImage);

    float velx = 0, vely = 0;
    float x = 10, y = 10, moveSpeed = 0.1;
    int sourceX = 0, sourceY =sDown;

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        if(Window.GetInput().IsKeyDown(sf::Key::Right))
        {
            sourceY = sRight;
            velx = moveSpeed;
        }
        else if(Window.GetInput().IsKeyDown(sf::Key::Left))
        {
            sourceY = sLeft;
            velx = -moveSpeed;
        }
        else
            velx = 0;

        if(Window.GetInput().IsKeyDown(sf::Key::Up))
        {
            sourceY = sUp;
            vely = -moveSpeed;
        }
        else if(Window.GetInput().IsKeyDown(sf::Key::Down))
        {
            sourceY = sDown;
            vely = moveSpeed;
        }
        else
            vely = 0;

        x += velx;
        y += vely;

        if(velx != 0 || vely != 0)
            sourceX += tempImage.GetWidth() / 4;
        else
            sourceX = 0;

        if(sourceX == tempImage.GetWidth())
            sourceX = 0;

        Window.Clear();
        playerSprte.SetSubRect(sf::IntRect(sourceX, sourceY, sourceX + tempImage.GetWidth() / 4, sourceY + tempImage.GetHeight() / 4));
        playerSprte.SetPosition(x, y);
        Window.Draw(playerSprte);
        Window.Display();
    }
    return 0;
}