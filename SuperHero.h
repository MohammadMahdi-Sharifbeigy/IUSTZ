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

  SuperHero(const std::string &name,int age, double hp, double attack, double defense, characterType role);
  ~SuperHero();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override;
  void SuperHeroToFile(string username);
  void FileToSuperHero(string username);
};

#endif // SUPERHERO_H
