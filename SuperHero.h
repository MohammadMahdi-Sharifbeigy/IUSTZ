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
  SuperHero() = default;
  SuperHero(const string& name,
            int age,
            double hp,
            double attack,
            double defense,
            characterType role,
            int coin);
  ~SuperHero();

  void performAttack(Character& target) override;
  void performAttack(Human& target) override;  
  void performDefense(Character& attacker) override;
  void performDefense(Human& attacker) override;
  virtual void levelUp() override;
  void SuperHeroToFile(const string& username);
  void FileToSuperHero(const string& username);
};

#endif  // SUPERHERO_H
