#ifndef __ATTACKSTRATEGY_H__
#define __ATTACKSTRATEGY_H__

class Character;
class Enemy;

class AttackStrategy {
 public:
  AttackStrategy() {}
  virtual int attackEnemy(Character *currCharacter, Enemy * currenemy) = 0;
  virtual int defenseEnemy(Character *currCharacter, Enemy *currenemy) = 0;
};

#endif //__ATTACKSTRATEGY_H__