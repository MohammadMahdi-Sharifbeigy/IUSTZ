#ifndef ASIANMOM_H
#define ASIANMOM_H

#include "AsianmomAttack.h"
#include "Human.h"
#include "../CharacterType.h"
#include "../CharacterType.h"

using namespace std;

class AsianMom : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  AsianMom() = default;
  AsianMom(const string& name,
           int age,
           double hp,
           double attack,
           double defense,
           characterType role,
           int coin);
  ~AsianMom();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void AsianMomToFile(string username);
  void FileToAsianMom(string username);
};

#endif  // ASIANMOM_H