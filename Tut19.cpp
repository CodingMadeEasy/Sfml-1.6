// C++ Made Easy Tutorial 19 - Circular Collision 
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

void Collision(sf::Shape player, sf::Shape &object)
{
   if((abs(player.GetPosition().x - object.GetPosition().x)) +
      abs((player.GetPosition().y - object.GetPosition().y)) <= 10)
   {
       object.SetPosition(rand() % (ScreenWidth - OBJECTWIDTH), rand() % (ScreenHeight - OBJECTHEIGHT));
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
    sf::Shape player = sf::Shape::Circle(0, 0, 5, sf::Color::Red);
    sf::Shape object = sf::Shape::Circle(0, 0, 5, sf::Color::Blue);

    player.SetPosition(0, 0);
    object.SetPosition(100, 100);

    /*player.SetPointColor(0, sf::Color::Black);
    player.SetPointColor(1, sf::Color::Yellow);
    player.SetPointColor(2, sf::Color::Cyan);
    player.SetPointColor(3, sf::Color::Green);*/

    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight), "SFML - CodingMadeEasy");

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
        Collision(player, object);

        Window.Clear();
        Window.Draw(player);
        Window.Draw(object);
        Window.Display();
    }
    return 0;
}
