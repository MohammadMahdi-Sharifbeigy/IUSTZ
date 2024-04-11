#include "GameState.h"

GameState::GameState(Human* player)
    : playerCharacter(player), gameOver(false) {}

GameState::~GameState() {}

Human* GameState::getPlayerCharacter() const {
  return playerCharacter;
}

Shop& GameState::getGameShop() {
  return gameShop;
}

bool GameState::isGameOver() const {
  return gameOver;
}

void GameState::setGameOver(bool state) {
  gameOver = state;
}
