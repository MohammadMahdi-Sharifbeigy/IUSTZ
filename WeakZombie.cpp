#include "WeakZombie.h"
#include <cmath>
#include <cstdlib>

using namespace std;

WeakZombie::WeakZombie() {}

WeakZombie::WeakZombie(int level) : Enemy(level) {
  role = WEAKZOMBIE;
  srand(time(NULL));
  maxHP = level + rand() % (3 * level / 4); // Weaker health
    currHP = maxHP;
  attack = 2 * level + rand() % (3 * level / 4); // Weaker attack
  defense = level + rand() % (3 * level / 4); // Weaker defense
  level = abs(level - 4 + rand() % 6) + 1; // More variability in level
  giveExp = level * 5 * attack / defense; // Less experience given
}
