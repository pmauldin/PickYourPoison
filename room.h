#pragma once
#include <SFML/Graphics.hpp>

class Room {
public:
  Room(const sf::Font& font);
  ~Room();

  void Update();
  void Draw(sf::RenderWindow& window);
private:
  sf::Text sprite;
};
