#ifndef PALADIN_H
#define PALADIN_H

#include "PaladinAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class Paladin : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  Paladin(const std::string &name, double hp, double attack, double defense, characterType role);
  ~Paladin();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
};

#endif // PALADIN_H
