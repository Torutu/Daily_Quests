#ifdef USE_SFML

#include "../headers/updateCSV.hpp"
#include "../headers/quests.hpp"
#include "../headers/displayProgress.hpp"
#include <SFML/Graphics.hpp>

// Helper function to display the progress window
void displayProgress() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Quest Tracker");

    sf::Font font;
    if (!font.loadFromFile("./src/fonts/DejaVuSansMono.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    sf::Text text("aight we will check the progress very soon :3", font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(40, 40);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }
}

#endif // USE_SFML
