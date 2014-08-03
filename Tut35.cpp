// C++ Sfml Made Easy Tutorial 35 - Gravity
// CodingMadeEasy

#include<SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

#define ScreenWidth 800
#define ScreenHeight 600

#define BLOCKSIZE 40

int loadCounterX, loadCounterY;
int mapSizeX, mapSizeY;
std::vector < std::vector <int> > MapVector;
std::vector <sf::Image> textureVector;

enum Identifier { MAP, TEXTURE };

int loadType = -1;

void LoadMap(const char *filename)
{
    sf::Image image;
    sf::Sprite sprite;
    std::ifstream openfile(filename);
    std::vector <int> tempVector;

    std::string line;

    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            std::getline(openfile, line);

            std::cout << line << std::endl;

            if(line.find("Map") != std::string::npos)
            {
                loadType = MAP;
                continue;
            }
            else if (line.find("Texture") != std::string::npos)
            {
                loadType = TEXTURE;
                continue;
            }

            std::string tempLine = line.erase(line.find_last_not_of(" ") + 1);
            int space = tempLine.find_first_of(" ");
            if(space == 0)
                tempLine = tempLine.erase(0, space + 1);
            std::stringstream str(tempLine);

            switch(loadType)
            {
                case MAP:
                    while(!str.eof())
                    {
                        std::string value;
                        getline(str, value, ' ');
                        if(value.length() > 0)
                            tempVector.push_back(atoi(value.c_str()));
                    }
                    MapVector.push_back(tempVector);
                    tempVector.clear();
                    break;

                case TEXTURE:
                    if(tempLine.length() > 0)
                    {
                        if(image.LoadFromFile(tempLine))
                        {
                            textureVector.push_back(image);
                        }
                        else
                        {
                            std::cout << "Could not load" << line << std::endl;
                        }
                        break;
                    }
            }
        }
    }
}

void DrawMap(sf::RenderWindow &Window)
{
    sf::Shape rect = sf::Shape::Rectangle(0, 0, BLOCKSIZE, BLOCKSIZE, sf::Color(255, 255, 255, 255));
    sf::Color rectCol;
    sf::Sprite sprite;
    for(int i = 0; i < MapVector.size(); i++)
    {
        for(int j = 0; j < MapVector[i].size(); j++)
        {
            if(MapVector[i][j] < 0)
            {
                rectCol = sf::Color(44, 117, 255);
                rect.SetPosition(j * BLOCKSIZE, i * BLOCKSIZE);
                rect.SetColor(rectCol);
                Window.Draw(rect);
            }
            else
            {
                sprite.SetImage(textureVector[MapVector[i][j]]);
                sprite.SetPosition(j * BLOCKSIZE, i * BLOCKSIZE);
                Window.Draw(sprite);
            }
        }
    }
}

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML Made Easy");
    sf::Shape rect = sf::Shape::Rectangle(0, 0, 10, 10, sf::Color::Red);
    LoadMap("Map1.txt");

    sf::Vector2f playerPosition(100, 100);
    sf::Vector2f playerVelocity(0, 0);
    const float gravity = 0.1;
    int groundHeight = (MapVector.size() - 2) * BLOCKSIZE;
    float jumpSpeed = 10, moveSpeed = 5;
    bool jump = false;

    rect.SetPosition(playerPosition);

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
        }

        if(Window.GetInput().IsKeyDown(sf::Key::Right))
            playerVelocity.x = moveSpeed;
        else if(Window.GetInput().IsKeyDown(sf::Key::Left))
            playerVelocity.x = -moveSpeed;
        else
            playerVelocity.x = 0;

        if(Window.GetInput().IsKeyDown(sf::Key::Up) && jump)
        {
            playerVelocity.y = -jumpSpeed;
            jump = false;
        }

        if(!jump)
            playerVelocity.y += gravity;
        else
            playerVelocity.y = 0;

        playerPosition += playerVelocity;

        jump = playerPosition.y + 10 >= groundHeight;

        if(jump)
            playerPosition.y = groundHeight - 10;

        rect.SetPosition(playerPosition);

        Window.Clear();
        DrawMap(Window);
        Window.Draw(rect);
        Window.Display();
    }
    return 0;
}
