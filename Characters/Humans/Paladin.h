#ifndef PALADIN_H
#define PALADIN_H

#include "PaladinAttack.h"
#include "Human.h"
#include "../Character.h"
#include "../CharacterType.h"

using namespace std;

class Paladin : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  Paladin() = default;
  Paladin(const string& name,
          int age,
          double hp,
          double attack,
          double defense,
          characterType role,
          int coin);
  ~Paladin();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void PaladinToFile(const string& username);
  void FileToPaladin(const string& username);
};

#endif  // PALADIN_H
