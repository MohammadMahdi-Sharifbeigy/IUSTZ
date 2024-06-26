#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "AssassinAttack.h"
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"

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
  void performAttack(Human& target) override;
  void performDefense(Character& attacker) override;
  void performDefense(Human& attacker) override;
  virtual void levelUp() override;
  void AssassinToFile(Human* player);
  void FileToAssassin(const string& username);
};

#endif  // ASSASSIN_H
