#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
#include "synth.h"
#include "input.h"


std::map<sf::Keyboard::Key, bool> keyState;

// Map for "piano" key inputs
std::map<sf::Keyboard::Key, double> keyToFrequency =
        {
                {sf::Keyboard::A, 261.63}, // C4
                {sf::Keyboard::W, 277.18}, // C#4 / Db4
                {sf::Keyboard::S, 293.66}, // D4
                {sf::Keyboard::E, 311.13}, // D#4 / Db4
                {sf::Keyboard::D, 329.63}, // E4
                {sf::Keyboard::F, 349.23}, // F4
                {sf::Keyboard::T, 369.99}, // F#4 / Gb4
                {sf::Keyboard::G, 392.00}, // G4
                {sf::Keyboard::Y, 415.30}, // G#4 / Ab4
                {sf::Keyboard::H, 440.00}, // A4
                {sf::Keyboard::U, 466.16}, // Bb4 / A#4
                {sf::Keyboard::J, 493.86}, // B4
                {sf::Keyboard::K, 523.25}, // C5
                {sf::Keyboard::O, 554.37}, // C#5 / Db5
                {sf::Keyboard::L, 587.33}, // D5
                {sf::Keyboard::P, 622.25}, // D#5 / Eb5
                {sf::Keyboard::Semicolon, 659.26} // E5
        };


// keys 1, 2, 3, and 4
// set different waveforms
std::map<sf::Keyboard::Key, WaveType> keyToWaveType =
        {
                {sf::Keyboard::Num1, WaveType::SINE},
                {sf::Keyboard::Num2, WaveType::SQUARE},
                {sf::Keyboard::Num3, WaveType::SAWTOOTH},
                {sf::Keyboard::Num4, WaveType::TRIANGLE}
        };


void handleInput(Synth& synth, sf::RenderWindow& window)
{
    // Event object to hold the event data
    sf::Event event;
    bool isAnyKeyPressed = false;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {

            // Handle key press events
            if (event.key.code == sf::Keyboard::Up)
            {
                synth.octaveUp();
                printf("OCTAVE: %i \n", synth.getOctave());
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                synth.octaveDown();
                printf("OCTAVE: %i \n", synth.getOctave());
            }
            else if (keyToWaveType.find(event.key.code) != keyToWaveType.end())
            {
                synth.setWaveType(keyToWaveType[event.key.code]);
                std::cout << "WAVETYPE: " << synth.getWaveType() << std::endl;
            }

            else if (keyToFrequency.find(event.key.code) != keyToFrequency.end())
            {
                // old monophonic code
                // synth.setFrequency(keyToFrequency[event.key.code]);

                synth.noteOn(keyToFrequency[event.key.code]);
                keyState[event.key.code] = true;
                isAnyKeyPressed = true;

                if (synth.getStatus() != sf::SoundStream::Playing)
                {
                    synth.play();
                }

            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            // Stop the synth when the key is released
            if (keyToFrequency.find(event.key.code) != keyToFrequency.end())
            {
                synth.noteOff(keyToFrequency[event.key.code]);
                synth.stop();
                isAnyKeyPressed = false;
            }
        }
    }
}
