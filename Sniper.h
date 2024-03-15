#ifndef SNIPER_H
#define SNIPER_H

#include "SniperAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class Sniper : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  Sniper(const std::string &name, double hp, double attack, double defense, characterType gold);
  ~Sniper();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
};

#endif // SNIPER_H
