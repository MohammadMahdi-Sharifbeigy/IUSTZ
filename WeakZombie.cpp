#include "WeakZombie.h"
#include "ASCIIArt/ASCIIArts.h"

using namespace std;

WeakZombie::WeakZombie() {}

WeakZombie::WeakZombie(int level) : Enemy(level) {
  Character::name = "Weak Zombie";
  role = WEAKZOMBIE;
  srand(time(NULL));\
  level ++;
  maxHP = level + rand() % (3 * level / 4) + 100; // Weaker health
  currHP = maxHP;
  attack = 2 * level + rand() % (3 * level / 4); // Weaker attack
  if (attack == 0) {
      attack = 5.0;
  }
  defense = level + rand() % (3 * level / 4); // Weaker defense
  if (defense == 0) {
     defense = 5.0;
  }
  level = abs(level - 4 + rand() % 6) + 1; // More variability in level
  giveExp = level * 5 * attack / defense; // Less experience given
}

WeakZombieModel::WeakZombieModel() {}

WeakZombie* WeakZombieModel::createWeakZombie(int level, Human* human) {
  return dynamic_cast<WeakZombie*>(EnemyFactory::createEnemy(WEAKZOMBIE, level, human));
}

WeakZombieView::WeakZombieView() {}

void WeakZombieView::displayWeakZombie(WeakZombie* weakZombie) {
    std::cout << "Weak Zombie created with level: " << weakZombie->get_enemy_lvl() << std::endl;
  std::cout << Zambia1 << std::endl;
}
WeakZombieController::WeakZombieController(WeakZombieModel* model, WeakZombieView* view)
    : model(model), view(view) {}

void WeakZombieController::createAndDisplayWeakZombie(int level, Human* human) {
  WeakZombie* weakZombie = model->createWeakZombie(level, human);
  if (weakZombie != nullptr) {
    view->displayWeakZombie(weakZombie);
  }
}