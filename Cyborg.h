#ifndef CYBORG_H
#define CYBORG_H

#include "Character.h"
#include "CharacterType.h"
#include "CyborgAttack.h"
#include "Human.h"

using namespace std;

class Cyborg : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  Cyborg() = default;
  Cyborg(const string& name,
         int age,
         double hp,
         double attack,
         double defense,
         characterType role,
         int coin);
  ~Cyborg();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void CyborgToFile(string username);
  void FileToCyborg(string username);
};

#endif  // CYBORG_H
