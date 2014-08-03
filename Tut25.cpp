// C++ Sfml Made Easy Tutorial 25 - Mouse Routines 
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

void MouseClick(sf::RenderWindow &Window, sf::Music &introMusic)
{
    int mouseX = Window.GetInput().GetMouseX();
    int mouseY = Window.GetInput().GetMouseY();
    if(Window.GetInput().IsMouseButtonDown(sf::Mouse::Left) && mouseX >= 350 && mouseX <= 450)
    {
        if(mouseY > 100 && mouseY < 200)
            introMusic.Play();
        else if (mouseY > 200 && mouseY < 300)
            introMusic.Pause();
        else if (mouseY > 300 && mouseY < 400)
            introMusic.Stop();
    }
}

int main()
{
    sf::Shape play = sf::Shape::Rectangle(350, 100, 450, 200, sf::Color::Green);
    sf::Shape pause = sf::Shape::Rectangle(350, 200, 450, 300, sf::Color::Yellow);
    sf::Shape stop = sf::Shape::Rectangle(350, 300, 450, 400, sf::Color::Red);

    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML - CodingMadeEasy");

    sf::Music introMusic;
    introMusic.OpenFromFile("intro.ogg");

    sf::Font gameFont;
    gameFont.LoadFromFile("Blade 2.ttf", 30);
    sf::String gameText;

    gameText.SetFont(gameFont);
    gameText.SetColor(sf::Color(44, 117, 255));

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        MouseClick(Window, introMusic);

        Window.Clear();
        gameText.SetPosition(350, 110);
        gameText.SetText("Play");
        Window.Draw(play);
        Window.Draw(gameText);
        gameText.SetPosition(350, 210);
        gameText.SetText("Pause");
        Window.Draw(pause);
        Window.Draw(gameText);
        gameText.SetPosition(350, 310);
        gameText.SetText("Stop");
        Window.Draw(stop);
        Window.Draw(gameText);
        Window.Display();
    }
    return 0;
}
