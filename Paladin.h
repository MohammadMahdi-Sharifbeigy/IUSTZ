#ifndef PALADIN_H
#define PALADIN_H

#include "Character.h"
#include "CharacterType.h"
#include "Human.h"
#include "PaladinAttack.h"

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
  void PaladinToFile(string username);
  void FileToPaladin(string username);
};

#endif  // PALADIN_H
