#include "player.h"
#include "constants.h"

Player::Player(const sf::Font& font) : Entity(font) {
  sprite.setString('@');
  sprite.setFillColor(sf::Color(255, 215, 0));

  x = MAP_WIDTH / 4;
  y = MAP_HEIGHT / 2;
  sprite.setPosition(x * TILE_SIZE_X, y * TILE_SIZE_Y);
}

sf::Vector2i getPlayerMove();

void Player::Update() {
  if (clock.getElapsedTime().asMilliseconds() < INPUT_COOLDOWN) return;

  auto playerMove = getPlayerMove();

  if (playerMove.x == 0 && playerMove.y == 0) return;

  if (playerMove.x != 0 && playerMove.y != 0) {
    playerMove.y = 0; // prioritize horizontal movement
  }

  int newX = x + playerMove.x;
  int newY = y + playerMove.y;

  if (newX < 1 || newX >= MAP_WIDTH - 1 || newY < 1 || newY >= MAP_HEIGHT - 1) {
    if (newX == MAP_WIDTH - 1 && newY == 8) {
      printf("You are winner!\n");
    } else {
      return;
    }
  };

  x += playerMove.x;
  y += playerMove.y;

  sprite.setPosition(x * TILE_SIZE_X, y * TILE_SIZE_Y);
  clock.restart();
}

sf::Vector2i getPlayerMove() {
  sf::Vector2i playerMove;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    playerMove.x -= 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    playerMove.x += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    playerMove.y -= 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    playerMove.y += 1;
  }

  return playerMove;
}
