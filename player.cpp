#include "player.h"

Player::Player(const sf::Font& font) {
  sprite.setFont(font);
  sprite.setString('@');
  sprite.setCharacterSize(64);
  sprite.setFillColor(sf::Color(255, 215, 0));
  sprite.setStyle(sf::Text::Bold);
  sprite.setPosition(450, 450);
}

Player::~Player() {}

void Player::Update() {}

void Player::Draw(sf::RenderWindow& window) {
  window.draw(sprite);
}
