#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
  Entity(const sf::Font& font);

  void Draw(sf::RenderWindow& window);

  sf::Vector2f GetPosition();
protected:
  int x, y;
  sf::Text sprite;
};