//
// Created by Daniel Bartolini on 5/25/24.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "synth.h"
#include "input.h"

std::map<sf::Keyboard::Key, double> keyToFrequency =
        {
                std::make_pair(sf::Keyboard::A, 261.63), // C4
                std::make_pair(sf::Keyboard::W, 277.18), // C#4 / Db4
                std::make_pair(sf::Keyboard::S, 293.66), // D4
                std::make_pair(sf::Keyboard::E, 311.13), // D#4 / Db4
                std::make_pair(sf::Keyboard::D, 329.63), // E4
                std::make_pair(sf::Keyboard::F, 349.23), // F4
                std::make_pair(sf::Keyboard::T, 369.99), // F#4 / Gb4
                std::make_pair(sf::Keyboard::G, 392.00), // G4
                std::make_pair(sf::Keyboard::Y, 415.30), // G#4 / Ab4
                std::make_pair(sf::Keyboard::H, 440.00), // A4
                std::make_pair(sf::Keyboard::U, 466.16), // Bb4 / A#4
                std::make_pair(sf::Keyboard::J, 493.86) // B4
        };

void handleInput(Synth& synth)
{
    bool isKeyPressed = false;

    for (const auto& [key, freq] : keyToFrequency)
    {
        if (sf::Keyboard::isKeyPressed(key))
        {
            synth.setFrequency(freq);

            if (synth.getStatus() != sf::SoundStream::Playing)
            {
                synth.play();
            }

            isKeyPressed = true;
            break;
        }
    }

    if (!isKeyPressed)
    {
        synth.stop();
    }
}
