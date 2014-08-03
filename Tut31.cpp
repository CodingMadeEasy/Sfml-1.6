// C++ Sfml Made Easy Tutorial 29 - Loading Tile Maps [Hard]
// CodingMadeEasy

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define ScreenWidth 800
#define ScreenHeight 600

#define BLOCKSIZE 40

std::vector < std::vector <int> > MapVector;

void LoadMap(const char *filename)
{
    std::ifstream openfile(filename);
    std::vector <int> tempVector;

    std::string line;

    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::getline(openfile, line);

            for(int i = 0; i < line.length(); i++)
            {
                if(line[i] != ' ')
                {
                    char value[1] = {line[i]};
                    tempVector.push_back(atoi(value));
                }
            }
            MapVector.push_back(tempVector);
            tempVector.clear();
        }
    }
}

void DrawMap(sf::RenderWindow &Window)
{
    sf::Shape rect = sf::Shape::Rectangle(0, 0, BLOCKSIZE, BLOCKSIZE, sf::Color(255, 255, 255, 255));
    sf::Color rectCol;
    for(int i = 0; i < MapVector.size(); i++)
    {
        for(int j = 0; j < MapVector[i].size(); j++)
        {
            if(MapVector[i][j] == 0)
                rectCol = sf::Color(44, 117, 255);
            else if (MapVector[i][j] == 1)
                rectCol = sf::Color(255, 100, 17);

            rect.SetPosition(j * BLOCKSIZE, i * BLOCKSIZE);
            rect.SetColor(rectCol);
            Window.Draw(rect);
        }
    }
}

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML Made Easy");

    LoadMap("Map2.txt");
    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        Window.Clear();
        DrawMap(Window);
        Window.Display();
    }
    return 0;
}
