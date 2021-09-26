#pragma once
#include "entity.h"

class Player : public Entity {
public:
  Player(const sf::Font& font);

  void Update();
private:
  sf::Clock clock;
};