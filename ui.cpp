//
// Created by Daniel Bartolini on 5/25/24.
//

#include "ui.h"
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Text renderUI(const sf::Font& font)
{

    // Create text instructions
    // TODO: Create a real UI . . .
    sf::Text instructions;

    instructions.setFont(font);
    instructions.setString("Press keys A-J (and W-U) to play notes");
    instructions.setCharacterSize(24);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(10, 10);

    return instructions;
}
