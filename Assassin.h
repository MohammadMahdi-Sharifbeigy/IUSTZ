#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "AssassinAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"


class Assassin : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  Assassin(const std::string &name, double hp, double attack, double defense, characterType role);
  ~Assassin();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
};

#endif // ASSASSIN_H
