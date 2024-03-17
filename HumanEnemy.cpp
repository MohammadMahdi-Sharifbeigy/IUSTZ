#include "HumanEnemy.h"
#include "cmath"

using namespace std;

HumanEnemy::HumanEnemy(Human& ref) : humanRef(ref) {}

HumanEnemy::HumanEnemy(int level, Human& ref) : Enemy(level), humanRef(ref) {
  srand(time(NULL));
  hp = 2 * level + rand() % (5 * level / 4);
  attack = 4 * level + rand() % (5 * level / 4);
  defense = 2 * level + rand() % (5 * level / 4);
  level = abs(level - 4 + rand() % 6) + 1;
  giveExp = level * 10 * attack / defense;
  role = getRandomRole();  // Set role randomly
}

HumanEnemy::HumanEnemy(int level, Human& ref, Human& human)
    : Enemy(level), humanRef(ref) {
  srand(time(NULL));
  hp = 2 * level + rand() % (5 * level / 4);
  attack = 4 * level + rand() % (5 * level / 4);
  defense = 2 * level + rand() % (5 * level / 4);
  level = abs(level - 4 + rand() % 6) + 1;
  giveExp = level * 10 * attack / defense;
  setRoleBasedOnHuman(human);  // Set role based on the Human it is fighting
}

// Function to generate a random characterType
characterType HumanEnemy::getRandomRole() {
  int role = rand() % 9;
  if (role == 7 || role == 8) {
    role = rand() % 9;
  }
  return static_cast<characterType>(role);
}

// Function to set role based on the Human it is fighting
void HumanEnemy::setRoleBasedOnHuman(Human& human) {
  this->role = human.getRole();
}

double HumanEnemy::attackChar(double charDefense) {
  return abs((((((2 * level / 3) + 2) * (40 + (level * 9 / 10)) * attack) /
               charDefense) /
              50) +
             2);
}