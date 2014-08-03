// C++ Sfml Made Easy Tutorial 34 - Recording Sounds
// CodingMadeEasy

#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

#define ScreenWidth 800
#define ScreenHeight 600

int main()
{
    sf::RenderWindow Window(sf::VideoMode(ScreenWidth, ScreenHeight, 32), "SFML Made Easy");

    sf::SoundBufferRecorder recorder;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    bool playRecording = true;

    while(Window.IsOpened())
    {
        sf::Event Event;
        while(Window.GetEvent(Event))
        {
            if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
                Window.Close();
            if(Event.Key.Code == sf::Key::R)
            {
                if(sf::SoundRecorder::CanCapture())
                    recorder.Start();
                else
                    std::cout << "Error" << std::endl;
            }
            if(Event.Key.Code == sf::Key::S && !playRecording)
            {
                recorder.Stop();
                soundBuffer = recorder.GetBuffer();
                sound.SetBuffer(soundBuffer);
                playRecording = true;
            }
        }

        Window.Clear();
        if(playRecording)
        {
            sound.Play();
            playRecording = false;
        }
        Window.Display();
    }
    return 0;
}
