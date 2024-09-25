//
// Created by Daniel Bartolini on 5/25/24.
//

#include "ui.h"
#include <SFML/Graphics.hpp>



std::array<sf::Text, 4> renderUI(const sf::Font& font, std::string waveType)
{

    // Create text keyboardInstructions
    // TODO: Create a real UI . . .

    sf::Text keyboardInstructions;
    keyboardInstructions.setFont(font);
    keyboardInstructions.setString("Press keys A-J (and W-U) to play notes!");
    keyboardInstructions.setCharacterSize(24);
    keyboardInstructions.setFillColor(sf::Color::White);
    keyboardInstructions.setPosition(50, 200);

    sf::Text octaveInstructions;
    octaveInstructions.setFont(font);
    octaveInstructions.setString("Use the up and down arrow keys to change octave.");
    octaveInstructions.setCharacterSize(20);
    octaveInstructions.setFillColor(sf::Color::White);
    octaveInstructions.setPosition(50, 250);

    sf::Text waveformInstructions;
    waveformInstructions.setFont(font);
    waveformInstructions.setString("Press 1-4 to change waveforms.");
    waveformInstructions.setCharacterSize(20);
    waveformInstructions.setFillColor(sf::Color::White);
    waveformInstructions.setPosition(50, 300);

    sf::Text currentWaveform;
    currentWaveform.setFont(font);
    currentWaveform.setString(waveType);
    currentWaveform.setCharacterSize(20);
    currentWaveform.setFillColor(sf::Color::White);
    currentWaveform.setPosition(50, 360);


    return
    {
        keyboardInstructions,
        octaveInstructions,
        waveformInstructions,
        currentWaveform
    };
}
