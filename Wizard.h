#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include "CharacterType.h"
#include "Human.h"
#include "WizardAttack.h"

using namespace std;

class Wizard : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  Wizard() = default;
  Wizard(const string& name,
         int age,
         double hp,
         double attack,
         double defense,
         characterType role,
         int coin);
  ~Wizard();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void WizardToFile(string username);
  void FileToWizard(string username);
};

#endif  // WIZARD_H
