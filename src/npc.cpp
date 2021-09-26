#include "npc.h"
#include "constants.h"

NPC::NPC(const sf::Font& font, Entity& player, int startX, int startY, int direction) : Entity(font), player(player), direction(direction) {
  sprite.setString('N');
  sprite.setFillColor(sf::Color(180, 30, 30));

  x = startX;
  y = startY;
  sprite.setPosition(x * TILE_SIZE_X, y * TILE_SIZE_Y);
}

sf::Vector2i getNPCMove(int direction);

void NPC::Update() {
  if (clock.getElapsedTime().asMilliseconds() < INPUT_COOLDOWN / 2) return;

  auto npcMove = getNPCMove(direction);

  if (npcMove.x == 0 && npcMove.y == 0) return;

  if (npcMove.x != 0 && npcMove.y != 0) {
    npcMove.x = 0; // prioritize vertical movement
  }

  int newX = x + npcMove.x;
  int newY = y + npcMove.y;

  if (newX < 1 || newX >= MAP_WIDTH - 1 || newY < 1 || newY >= MAP_HEIGHT - 1) {
    direction *= -1;
    return;
  }

  x += npcMove.x;
  y += npcMove.y;

  if (x == player.GetPosition().x && y == player.GetPosition().y) {
    printf("You suck at this game!\n");
  }

  sprite.setPosition(x * TILE_SIZE_X, y * TILE_SIZE_Y);
  clock.restart();
}

sf::Vector2i getNPCMove(int direction) {
  sf::Vector2i npcMove;

  npcMove.y = 1 * direction;

  return npcMove;
}
