//
// Created by Daniel Bartolini on 5/25/24.
//

#ifndef SINE_WAVE_OSCILLATOR_UI_H
#define SINE_WAVE_OSCILLATOR_UI_H

#include <SFML/Graphics.hpp>
#include <array>

std::array<sf::Text, 4> renderUI(const sf::Font& font, std::string waveType);


#endif //SINE_WAVE_OSCILLATOR_UI_H
