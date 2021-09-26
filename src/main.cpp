#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "npc.h"
#include "room.h"
#include "constants.h"

static const float VIEW_HEIGHT = 720.0f;
static const float MS_PER_UPDATE = 1000.0f / 60;

int main() {
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1440, 720), "PickYourPoison", sf::Style::None);
    window.setPosition(sf::Vector2i(videoMode.width / 2 - window.getSize().x / 2, videoMode.height / 2 - window.getSize().y / 2));

    sf::View view(sf::Vector2f(MAP_WIDTH * TILE_SIZE_X / 2, MAP_HEIGHT * TILE_SIZE_Y / 1.8f), sf::Vector2f(VIEW_HEIGHT * 1.6f, VIEW_HEIGHT));
    window.setView(view);

    sf::Font font;
    if (!font.loadFromFile("assets/ProggySquare.ttf")) {
        printf("Failed to load font file\n");
        return -1;
    }

    Player player(font);
    NPC npc1(font, player, 12, 2, 1);
    NPC npc2(font, player, 16, 8, -1);
    Room room(font);

    sf::Clock clock;
    double lag = 0.0;
    double maxFrameTime = 0.0f;
    int frameCount = 0;
    while (window.isOpen()) {
        auto elapsed = clock.restart();
        double frameTimeMs = elapsed.asMilliseconds();
        lag += frameTimeMs;

        if (frameTimeMs > maxFrameTime) maxFrameTime = frameTimeMs;

        frameCount++;
        if (frameCount == 600) {
            frameCount = 0;
            double frameTime = elapsed.asMicroseconds();
            printf("Last frametime %.2fms, %.0f fps, %.1fms maxFrameTime\n", frameTime / 1000.f, 1000000.0f / (frameTime), maxFrameTime);
            maxFrameTime = 0;
        }

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        // Update
        while (lag >= MS_PER_UPDATE) {
            player.Update();
            npc1.Update();
            npc2.Update();
            lag -= MS_PER_UPDATE;
        }

        // Render
        window.clear(sf::Color(128, 128, 128));
        // view.setCenter(player.GetPosition());
        // window.setView(view);

        room.Draw(window);
        npc1.Draw(window);
        npc2.Draw(window);
        player.Draw(window);

        window.display();
    }

    return 0;
}
