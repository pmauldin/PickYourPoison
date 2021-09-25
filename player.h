#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
  Player(const sf::Font& font);
  ~Player();

  void Update();
  void Draw(sf::RenderWindow& window);
private:
  sf::Text sprite;
};