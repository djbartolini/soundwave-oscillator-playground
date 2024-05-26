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

    std::string fontPath = "/Library/Fonts/Arial\ Unicode.ttf";

    if (!font.loadFromFile(fontPath))
    {
        printf("Error loading SFML Font!");
        // TODO: Add real error handling
    }

    sf::Text instructions = renderUI(font);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput(synth);

        window.clear();
        window.draw(instructions);
        window.display();
    }

    return 0;
}
