#include "entity.h"
#include "constants.h"

Entity::Entity(const sf::Font& font) {
  sprite.setFont(font);
  sprite.setString("N/A");
  sprite.setCharacterSize(TILE_SIZE);
  sprite.setStyle(sf::Text::Bold);
  x = 0;
  y = 0;
}

sf::Vector2f Entity::GetPosition() {
  return sprite.getPosition();
}

void Entity::Draw(sf::RenderWindow& window) {
  window.draw(sprite);
}
