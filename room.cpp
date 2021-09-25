#include "room.h"

Room::Room(const sf::Font& font) {
  sprite.setFont(font);
  sprite.setString('#');
  sprite.setCharacterSize(64);
  sprite.setFillColor(sf::Color::Black);
  sprite.setStyle(sf::Text::Bold);
}

Room::~Room() {}

void Room::Update() {}

void Room::Draw(sf::RenderWindow& window) {
  int width = 64;
  float xPos = 100;
  for (int x = 0; x < 20; x++) {
    float yPos = 100;
    for (int y = 0; y < 15; y++) {
      if (!(x > 0 & x < 19 && y > 0 && y < 14)) {
        sprite.setPosition(xPos, yPos);
        window.draw(sprite);
      };

      yPos += width / 1.8f;
    }
    xPos += width / 2;
  }
  // window.draw(sprite);
}
