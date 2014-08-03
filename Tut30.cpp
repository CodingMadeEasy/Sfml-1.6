// C++ Sfml Made Easy Tutorial 29 - Loading Tile Maps [Intermediate]
// CodingMadeEasy

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#define ScreenWidth 800
#define ScreenHeight 600

#define BLOCKSIZE 40

int loadCounterX, loadCounterY;
int mapSizeX, mapSizeY;
int MapFile[100][100];

void LoadMap(const char *filename)
{
    std::ifstream openfile(filename);
    if(openfile.is_open())
    {
        std::string tempLine;
        std::getline(openfile, tempLine);

        tempLine.erase(std::remove (tempLine.begin(), tempLine.end(), ' '), tempLine.end());
        mapSizeX = tempLine.length();

        openfile.seekg(0, std::ios::beg);

        while(!openfile.eof())
        {
            openfile >> MapFile[loadCounterX][loadCounterY];
            loadCounterX++;
            if(loadCounterX >= mapSizeX)
            {
                loadCounterX = 0;
                loadCounterY++;
            }
        }
        mapSizeY = loadCounterY;
    }
}

void DrawMap(sf::RenderWindow &Window)
{
    sf::Shape rect = sf::Shape::Rectangle(0, 0, BLOCKSIZE, BLOCKSIZE, sf::Color(255, 255, 255, 255));
    sf::Color rectCol;
    for(int i = 0; i < mapSizeX; i++)
    {
        for(int j = 0; j < mapSizeY; j++)
        {
            if(MapFile[i][j] == 0)
                rectCol = sf::Color(44, 117, 255);
            else if (MapFile[i][j] == 1)
                rectCol = sf::Color(255, 100, 17);

            rect.SetPosition(i * BLOCKSIZE, j * BLOCKSIZE);
            rect.SetColor(rectCol);
            Window.Draw(rect);
        }
    }
}

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML Made Easy");

    LoadMap("Map1.txt");
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
