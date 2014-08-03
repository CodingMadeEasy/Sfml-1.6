// C++ Sfml Made Easy Tutorial 20 - Pixel and Additional Collision 
// CodingMadeEasy

#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cmath>

const int PLAYERWIDTH  = 10;
const int PLAYERHEIGHT = 10;
const int OBJECTWIDTH = 10;
const int OBJECTHEIGHT = 10;

const float MOVESPEED = 0.2f;

#define ScreenWidth 800
#define ScreenHeight 600

/*void Collision(sf::RenderWindow &Window, sf::Shape player, sf::Shape &object)
{
    if(player.GetPosition().x + PLAYERWIDTH < object.GetPosition().x ||
       player.GetPosition().x > object.GetPosition().x + OBJECTWIDTH ||
       player.GetPosition().y + PLAYERHEIGHT < object.GetPosition().y ||
       player.GetPosition().y > object.GetPosition().y + OBJECTHEIGHT)
    {
        // No Collision
    }
    else
    {
        sf::Image screenCapture = Window.Capture();
        for(int i = 0; i < PLAYERWIDTH; i++)
        {
            for(int j = 0; j < PLAYERHEIGHT; j++)
            {
                if(screenCapture.GetPixel(player.GetPosition().x + i, player.GetPosition().y + j) == sf::Color::Blue)
                {
                    object.SetPosition(rand() % (ScreenWidth - OBJECTWIDTH), rand() % (ScreenHeight - OBJECTHEIGHT));
                }
            }
        }
    }
}*/

void Collision(sf::RenderWindow &Window, sf::Shape player, sf::Shape &object)
{
    float dx = abs(player.GetPosition().x - object.GetPosition().x);
    float dy = abs(player.GetPosition().y - object.GetPosition().y);
    float hyp = sqrt(pow(dx, 2) + pow(dy, 2));

    std::cout << hyp << std::endl;

    if(hyp <= PLAYERWIDTH)
    {
        sf::Image screenCapture = Window.Capture();
        if(screenCapture.GetPixel(player.GetPosition().x, player.GetPosition().y) == sf::Color::Blue||
           screenCapture.GetPixel(player.GetPosition().x + PLAYERWIDTH, player.GetPosition().y) == sf::Color::Blue ||
           screenCapture.GetPixel(player.GetPosition().x, player.GetPosition().y + PLAYERHEIGHT) == sf::Color::Blue||
           screenCapture.GetPixel(player.GetPosition().x + PLAYERWIDTH, player.GetPosition().y + PLAYERHEIGHT)
           == sf::Color::Blue)
           {
               object.SetPosition(rand() % (ScreenWidth - OBJECTWIDTH), rand() % (ScreenHeight - OBJECTHEIGHT));
           }
    }
}

void Controls(sf::RenderWindow &Window, sf::Shape &player)
{
    if(Window.GetInput().IsKeyDown(sf::Key::Right))
        player.Move(MOVESPEED, 0);
    else if(Window.GetInput().IsKeyDown(sf::Key::Left))
        player.Move(-MOVESPEED, 0);
    else if(Window.GetInput().IsKeyDown(sf::Key::Down))
        player.Move(0, MOVESPEED);
    else if(Window.GetInput().IsKeyDown(sf::Key::Up))
        player.Move(0, -MOVESPEED);
}

int main()
{
    sf::Shape player = sf::Shape::Rectangle(0, 0, PLAYERWIDTH, PLAYERHEIGHT, sf::Color::Red);
    sf::Shape object = sf::Shape::Rectangle(0, 0, OBJECTWIDTH, OBJECTHEIGHT, sf::Color::Blue);

    player.SetPosition(0, 0);
    object.SetPosition(100, 100);

    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML - CodingMadeEasy");

    srand(time(0));

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        Controls(Window, player);

        Window.Clear();
        Window.Draw(object);
        Collision(Window, player, object);
        Window.Draw(player);
        Window.Display();
    }
    return 0;
}
