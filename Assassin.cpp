#include "Assassin.h"
#include "Character.h"
#include "AttackStrategy.h"
#include "Human.h"
#include "CharacterType.h"
#include "Enemy.h"
#include <iostream>

Assassin::Assassin(const std::string &name, double hp, double defense, double attack, characterType role)
    : Human(name, hp, attack, defense, role)
{
  attackStrategy = new AssassinAttack();
  age = 1;
  maxXP = 100;
  currXP = 0;
  stamina = 100.0;
  strength = 10.0;
  endurance = 10.0;
  accuracy = 10.0;
  pace = 10.0;
  mind = 10.0;
  coin = 0;
}

Assassin::~Assassin()
{
  delete attackStrategy;
}

void Assassin::performAttack(Character &target)
{
  if (attackStrategy)
  {
    if (Enemy *enemy = dynamic_cast<Enemy *>(&target))
    {
      attackStrategy->attackEnemy(this, enemy);
    }
  }
  else
  {
    std::cout << getName() << " attacks " << target.getName() << " with a basic attack." << std::endl;
  }
}

void Assassin::performDefense() {}

void Assassin::levelUp()
{
  while (getCurrentXP() >= getMaxXP())
  {
    std::cout << "You have leveled up!" << std::endl;
    setMaxHP(getMaxHP() + 30);
    setAttack(getAttack() + 10);
    setDefense(getDefense() + 5);
    setLevel(getLevel() + 1);
    setStamina(getStamina() + 15);
    setStrength(getStrength() + 2);
    setEndurance(getEndurance() + 2);
    setAccuracy(getAccuracy() + 2);
    setPace(getPace() + 2);
    setMind(getMind() + 2);
    setCurrXP(getCurrXP() - getMaxXP());
    setMaxXP(getMaxXP() + 25);

    std::cout << "Your level is now " << getLevel() << "!" << std::endl;
  }
}