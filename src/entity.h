#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
  Entity(const sf::Font& font);

  void Draw(sf::RenderWindow& window);

  const sf::Vector2i GetPosition();
protected:
  int x, y;
  sf::Text sprite;
};