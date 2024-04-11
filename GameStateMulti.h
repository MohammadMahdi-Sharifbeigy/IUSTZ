#ifndef GAMESTATEMULTI_H
#define GAMESTATEMULTI_H

#include "GameState.h"  // Assuming GameState includes necessary headers like "Human.h" and "Shop.h"

class GameStateMulti {
 private:
  Human* player1Character;  // First player's character
  Human* player2Character;  // Second player's character
  Shop gameShop;            // The in-game shop, shared by both players
  bool gameOver;            // Game state to determine if the game has ended

 public:
  // Constructor that takes two Human pointers for the two players
  GameStateMulti(Human* player1, Human* player2);

  // Destructor
  ~GameStateMulti();

  // Getter methods for both player characters
  Human* getPlayer1Character() const;
  Human* getPlayer2Character() const;

  // Since the shop is shared, this method remains unchanged
  Shop& getGameShop();

  // Game over state could depend on both players
  bool isGameOver() const;

  // Setter for the game over state
  void setGameOver(bool state);
};

#endif  // GAMESTATEMULTI_H
