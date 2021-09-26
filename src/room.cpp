#include "room.h"
#include "constants.h"

Room::Room(const sf::Font& font) {
  sprite.setFont(font);
  sprite.setString('#');
  sprite.setCharacterSize(TILE_SIZE);
  sprite.setFillColor(sf::Color::Black);
  sprite.setStyle(sf::Text::Bold);
}

Room::~Room() {}

void Room::Update() {}

void Room::Draw(sf::RenderWindow& window) {
  float xPos = 0;
  for (int x = 0; x < MAP_WIDTH; x++) {
    float yPos = 0;
    for (int y = 0; y < MAP_HEIGHT; y++) {
      if (!(x == MAP_WIDTH - 1 && y == (int)8) && (x == 0 || x == MAP_WIDTH - 1 || y == 0 || y == MAP_HEIGHT - 1)) {
        sprite.setPosition(xPos, yPos);
        window.draw(sprite);
      };

      yPos += TILE_SIZE_Y;
    }
    xPos += TILE_SIZE_X;
  }
}
