#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "SuperHeroAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class SuperHero : public Human
{
private:
  AttackStrategy *attackStrategy;

public:

  SuperHero(const std::string &name, double hp, double attack, double defense, characterType role);
  ~SuperHero();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
};

#endif // SUPERHERO_H
