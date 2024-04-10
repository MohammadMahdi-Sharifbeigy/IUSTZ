#ifndef CYBORG_H
#define CYBORG_H

#include "CyborgAttack.h"
#include "Human.h"
#include "../Character.h"
#include "../CharacterType.h"

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
  void CyborgToFile(const string& username);
  void FileToCyborg(const string& username);
};

#endif  // CYBORG_H
