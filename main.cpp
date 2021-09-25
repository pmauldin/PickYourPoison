#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "room.h"

static const float VIEW_HEIGHT = 1024.0f;
static const float speed = 0.3f;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "RogueHeavy", sf::Style::Resize);
    window.setPosition(sf::Vector2i(videoMode.width / 2 - window.getSize().x / 2, videoMode.height / 2 - window.getSize().y / 2));

    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    sf::Font font;
    if (!font.loadFromFile("assets/ProggySquare.ttf")) {
        printf("Failed to load font file\n");
        return -1;
    }

    Player player(font);
    Room room(font);

    // sf::RectangleShape background(sf::Vector2f(300, 50));
    // sf::RectangleShape square(sf::Vector2f(100, 100));
    // background.setFillColor(sf::Color::Green);
    // square.setFillColor(sf::Color::Cyan);
    // square.setOrigin(square.getSize() / 2.0f);
    // square.move(150, 150);

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //     square.move(sf::Vector2f(-speed, 0));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //     square.move(sf::Vector2f(speed, 0));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        //     square.move(sf::Vector2f(0, speed));
        // }
        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        //     square.move(sf::Vector2f(0, -speed));
        // }

        // view.setCenter(square.getPosition());

        window.clear(sf::Color(128, 128, 128));
        // window.setView(view);
        // window.draw(background);
        // window.draw(square);
        room.Draw(window);
        player.Draw(window);
        window.display();
    }

    return 0;
}
