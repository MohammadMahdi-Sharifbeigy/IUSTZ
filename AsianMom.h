#ifndef ASIANMOM_H
#define ASIANMOM_H

#include "AsianmomAttack.h"
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"

using namespace std;

class AsianMom : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  AsianMom() = default;
  AsianMom(const string& name, int age, double hp, double attack, double defense, characterType role, int coin);
  ~AsianMom();

  void performAttack(Character& target) override;
  void performAttack(Human& target) override;
  void performDefense(Character& attacker) override;
  void performDefense(Human& attacker) override;
  virtual void levelUp() override;

  void handleAttack(Character& target);
  void handleDefense(Character& attacker);
  void handleLevelUp();

  void AsianMomToFile(const string& username);
  void FileToAsianMom(const string& username);
};

#endif  // ASIANMOM_H
