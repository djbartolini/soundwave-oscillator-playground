#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include "sound.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sine Wave Oscillator");

    sf::SoundBuffer buffer;
    vector<sf::Int16> samples;

    sf::Sound silence;


    for (int i=0; i < 44100 * 0.5; i++)       // 0.5 seconds worth of sound at 44100 hz
    {
        samples.push_back(sound::SineWave(i, 392, 0.9));
    }

    for (int i=0; i < 44100 * 0.5; i++)       // 0.5 seconds worth of sound
    {
        samples.push_back(sound::SquareWave(i, 392, 0.9));
    }

    for (int i=0; i < 44100 * 0.5; i++)       // 0.5 seconds worth of sound
    {
        samples.push_back(sound::SawtoothWave(i, 392, 0.9));
    }

    for (int i=0; i < 44100 * 5.0; i++)       // 5 seconds worth of sound
    {
        samples.push_back(sound::TriangleWave(i, 392, 0.9));
    }

    for (int i=0; i < 44100 * 1; i++)       // 1 second worth of sound
    {
        samples.push_back(sound::Noise(0.9));
    }



    if (!buffer.loadFromSamples(&samples[0], samples.size(), 2, 44100))
    {
        // Error loading buffer
        return 1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);

    if (sound.getStatus() != sf::Sound::Playing)
    {
        sound.play();
    }

    printf("AUDIO STATUS: %i\n ", sound.getStatus());


    if (sound.getStatus() != sf::Sound::Playing)
    {
        // Error playing sound
        return 1;
    }

    // Game Loop
    while (window.isOpen())
    {
        sf::Event event;

        // printf("AUDIO STATUS: %i\n", sound.getStatus());

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }

    return 0;
}
