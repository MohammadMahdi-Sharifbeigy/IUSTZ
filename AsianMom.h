// AsianMom.h - Combining Model, View, and Controller
#ifndef ASIANMOM_H
#define ASIANMOM_H

#include "AsianmomAttack.h"
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"

using namespace std;

// Model
class AsianMom : public Human {
 private:
  AttackStrategy* attackStrategy;

 public:
  AsianMom() = default;
  AsianMom(const string& name, int age, double hp, double attack, double defense, characterType role, int coin);
  ~AsianMom();

  void performAttack(Character& target) override;
  void performDefense(Character& attacker) override;
  virtual void levelUp() override;
  void AsianMomToFile(string username);
  void FileToAsianMom(string username);
};

// View
class AsianMomView {
 public:
  void displayAsianMomStatus(AsianMom& asianMom); // Declaration only
};

// Controller
class AsianMomController {
 private:
  AsianMom model;
  AsianMomView view;

 public:
  AsianMomController(const AsianMom& model, const AsianMomView& view);
  void updateView();
  void handleAttack(Character& target);
  void handleDefense(Character& attacker);
  void handleLevelUp();
};

#endif  // ASIANMOM_H
