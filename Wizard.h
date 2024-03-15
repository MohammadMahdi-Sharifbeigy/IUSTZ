#ifndef WIZARD_H
#define WIZARD_H

#include "WizardAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class Wizard : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  Wizard(const std::string &name, double hp, double attack, double defense, characterType role);
  ~Wizard();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
};

#endif // WIZARD_H
