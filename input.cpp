//
// Created by Daniel Bartolini on 5/25/24.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "synth.h"
#include "input.h"

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
                {sf::Keyboard::J, 493.86} // B4
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


void handleInput(Synth& synth)
{
    // load key flag
    bool isKeyPressed = false;

    // loop to listen for changes in waveform
    // keys 1, 2, 3, or 4
    for (const auto& [key, waveType] : keyToWaveType)
    {
        if (sf::Keyboard::isKeyPressed(key))
        {
            synth.setWaveType(waveType);
        }
    }

    /*
     * KEY MAPPING
     * (PRETTY SELF EXPLANATORY):
     * `A`: C,
     * `W`: C#,
     * `S`: D,
     * `E`: Eb,
     * `D`: E,
     * `F`: F,
     * `T`: F#,
     * `G`: G,
     * `Y`: Ab,
     * `H`: A,
     * `U`: Bb,
     * `J`: B
     */

    for (const auto& [key, freq] : keyToFrequency)
    {
        if (sf::Keyboard::isKeyPressed(key))
        {
            synth.setFrequency(freq);

            if (synth.getStatus() != sf::SoundStream::Playing)
            {
                synth.play();
            }

            // key flag is true
            isKeyPressed = true;
            break;
        }
    }

    // when we release the key, the synth stops
    if (!isKeyPressed)
    {
        synth.stop();
    }

}
