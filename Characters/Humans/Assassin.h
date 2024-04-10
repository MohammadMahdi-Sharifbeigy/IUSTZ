#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "AssassinAttack.h"
#include "Human.h"
#include "../Character.h"
#include "../CharacterType.h"

using namespace std;

class Assassin : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  Assassin() = default;
  Assassin(const string& name,
           int age,
           double hp,
           double attack,
           double defense,
           characterType role,
           int coin);
  ~Assassin();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void AssassinToFile(const string& username);
  void FileToAssassin(const string& username);
};

#endif  // ASSASSIN_H
