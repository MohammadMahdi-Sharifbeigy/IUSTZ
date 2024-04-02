#ifndef SNIPER_H
#define SNIPER_H

#include "Character.h"
#include "CharacterType.h"
#include "Human.h"
#include "SniperAttack.h"

using namespace std;

class Sniper : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  Sniper() = default;
  Sniper(const string& name,
         int age,
         double hp,
         double attack,
         double defense,
         characterType gold,
         int coin);
  ~Sniper();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void SniperToFile(const string& username);
  void FileToSniper(const string& username);
};

#endif  // SNIPER_H
