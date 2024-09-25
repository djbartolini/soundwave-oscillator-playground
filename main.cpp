
#include <SFML/Graphics.hpp>
#include "synth.h"
#include "input.h"
#include "ui.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sound Wave Oscillator");
    Synth synth;

    // Load SFML Font
    sf::Font font;

    std::string fontPath = "/Library/Fonts/Arial Unicode.ttf";

    if (!font.loadFromFile(fontPath))
    {
        printf("Error loading SFML Font!");
        // TODO: Add real error handling
    }


    while (window.isOpen())
    {
        // Handle input and events
        handleInput(synth, window);

        std::string waveType = synth.getWaveType();

        std::array<sf::Text, 4> instructions = renderUI(font, waveType);

        // Clear the window and draw the UI
        window.clear();

        // Draw each instruction
        for (const auto& instruction : instructions)
        {
            window.draw(instruction);
        }

        window.display();
    }

    return 0;
}
