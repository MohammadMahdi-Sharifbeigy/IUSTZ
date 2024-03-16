#ifndef CYBORG_H
#define CYBORG_H

#include "CyborgAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"


class Cyborg : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  Cyborg(const std::string &name, double hp, double attack, double defense, characterType role);
  ~Cyborg();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
  void CyborgToFile(string username);
  void FileToCyborg(string username);
};

#endif // CYBORG_H
