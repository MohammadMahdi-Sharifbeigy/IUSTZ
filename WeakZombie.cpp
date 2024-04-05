#include "WeakZombie.h"
#include "ASCIIArt/ASCIIArts.h"

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

WeakZombieModel::WeakZombieModel() {}

WeakZombie* WeakZombieModel::createWeakZombie(int level, Human* human) {
  return dynamic_cast<WeakZombie*>(EnemyFactory::createEnemy(WEAKZOMBIE, level, human, nullptr));
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