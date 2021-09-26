#pragma once
#include "entity.h"

class NPC : public Entity {
public:
  NPC(const sf::Font& font, Entity& player, int startX, int startY, int direction);

  void Update();
private:
  sf::Clock clock;
  Entity& player;
  int direction;
};
