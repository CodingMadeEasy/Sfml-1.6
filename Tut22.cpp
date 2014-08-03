// C++ Sfml Made Easy Tutorial  22 - Music
// CodingMadeEasy

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

const int PLAYERWIDTH  = 10;
const int PLAYERHEIGHT = 10;
const int OBJECTWIDTH = 10;
const int OBJECTHEIGHT = 10;

const float MOVESPEED = 0.2f;

#define ScreenWidth 800
#define ScreenHeight 600

void Collision(sf::RenderWindow &Window, sf::Sound &collision, sf::Shape player, sf::Shape &object)
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
        collision.Play();
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
    sf::Shape player = sf::Shape::Rectangle(0, 0, PLAYERWIDTH, PLAYERHEIGHT, sf::Color::Red);
    sf::Shape object = sf::Shape::Rectangle(0, 0, OBJECTWIDTH, OBJECTHEIGHT, sf::Color::Blue);

    player.SetPosition(0, 0);
    object.SetPosition(100, 100);

    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML - CodingMadeEasy");

    sf::SoundBuffer buffer;
    sf::Sound collision;
    sf::Music introMusic;

    if(buffer.LoadFromFile("collision.wav"))
        collision.SetBuffer(buffer);
    introMusic.OpenFromFile("intro.ogg");

    srand(time(0));

    introMusic.Play();

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        Controls(Window, player);
        Collision(Window, collision, player, object);

        Window.Clear();
        Window.Draw(object);
        Window.Draw(player);
        Window.Display();
    }
    return 0;
}

// http://www.converfiles.com  - convert your files to .ogg format