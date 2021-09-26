#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

class Player : public Entity {
public:
  Player(const sf::Font& font);

  void Update();
private:
  int x, y;
  sf::Clock clock;
};