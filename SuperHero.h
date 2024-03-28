#ifndef SUPERHERO_H
#define SUPERHERO_H

#include "Character.h"
#include "CharacterType.h"
#include "Human.h"
#include "SuperHeroAttack.h"

using namespace std;

class SuperHero : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  SuperHero(const string& name,
            int age,
            double hp,
            double attack,
            double defense,
            characterType role,
            int coin);
  ~SuperHero();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void SuperHeroToFile(string username);
  void FileToSuperHero(string username);
};

#endif  // SUPERHERO_H
