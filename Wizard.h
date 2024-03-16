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
  Wizard(const std::string &name,int age, double hp, double attack, double defense, characterType role);
  ~Wizard();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override;
  virtual void levelUp() override; 
  void WizardToFile(string username);
  void FileToWizard(string username);
};

#endif // WIZARD_H
