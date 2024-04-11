#include "GameStateMulti.h"

// Constructor initializing both player characters, shared game shop, and
// initial game state.
GameStateMulti::GameStateMulti(Human* player1, Human* player2)
    : player1Character(player1), player2Character(player2), gameOver(false) {}

// Destructor
GameStateMulti::~GameStateMulti() {}

// Getters for player characters
Human* GameStateMulti::getPlayer1Character() const {
  return player1Character;
}

Human* GameStateMulti::getPlayer2Character() const {
  return player2Character;
}

// Getter for the shared game shop
Shop& GameStateMulti::getGameShop() {
  return gameShop;
}

// Check if the game is over
bool GameStateMulti::isGameOver() const {
  return gameOver;
}

// Set the game over state
void GameStateMulti::setGameOver(bool state) {
  gameOver = state;
}
