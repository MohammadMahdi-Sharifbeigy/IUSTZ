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
  Assassin(const string& name,
           int age,
           double hp,
           double attack,
           double defense,
           characterType role);
  ~Assassin();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void AssasinToFile(string username);
  void FileToAssasin(string username);
};

#endif  // ASSASSIN_H
