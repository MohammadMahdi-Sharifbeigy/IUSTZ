#ifndef ASIANMOM_H
#define ASIANMOM_H

#include "AsianmomAttack.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class AsianMom : public Human
{
private:
  AttackStrategy *attackStrategy;

public:
  AsianMom(const std::string &name, double hp, double attack, double defense, characterType role);
  ~AsianMom();

  void performAttack(Character &target) override;
  void performDefense(Enemy &attacker) override {};
  virtual void levelUp() override; 
  void AsianMomToFile(string username);
  void FileToAsianMom(string username);
};

#endif // ASIANMOM_H
