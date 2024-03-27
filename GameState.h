#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Human.h"
#include "Shop.h"

class GameState {
 private:
  Human* playerCharacter;  // The player's character
  Shop gameShop;           // The in-game shop
  bool gameOver;           // Game state to determine if the game has ended

 public:
  GameState(Human* player);
  ~GameState();

  Human* getPlayerCharacter() const;
  Shop& getGameShop();
  bool isGameOver() const;

  void setGameOver(bool state);
};

#endif  // GAMESTATE_H
