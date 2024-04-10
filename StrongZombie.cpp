#include "StrongZombie.h"
#include "ASCIIArt/ASCIIArts.h"

using namespace std;

StrongZombie::StrongZombie() {}

StrongZombie::StrongZombie(int level) : Enemy(level) {
  Character::name = "Strong Zombie";
  role = STRONGZOMBIE;
  srand(time(NULL));
  level++;
  maxHP = 3 * level + rand() % (5 * level / 2) + 100 ; // Stronger health
  currHP = maxHP;
  attack = 5 * level + rand() % (5 * level / 2); // Stronger attack
  if (attack == 0) {
      attack = 10.0;
  }
  defense = 3 * level + rand() % (5 * level / 2); // Stronger defense
  if (defense == 0) {
     defense = 10.0;
  }
  level = abs(level - 2 + rand() % 3) + 1; // Less variability in level
  giveExp = level * 15 * attack / defense; // More experience given
}

StrongZombieModel::StrongZombieModel() {}

StrongZombie* StrongZombieModel::createStrongZombie(int level, Human* human) {
  return dynamic_cast<StrongZombie*>(EnemyFactory::createEnemy(STRONGZOMBIE, level, human));
}

StrongZombieView::StrongZombieView() {}

void StrongZombieView::displayStrongZombie(StrongZombie* strongZombie) {
  std::cout << "Strong Zombie created with level: " << strongZombie->get_enemy_lvl() << std::endl;
  std::cout << DeathAngel << std::endl;
}

StrongZombieController::StrongZombieController(StrongZombieModel* model, StrongZombieView* view)
    : model(model), view(view) {}

void StrongZombieController::createAndDisplayStrongZombie(int level, Human* human) {
  StrongZombie* strongZombie = model->createStrongZombie(level, human);
  if (strongZombie != nullptr) {
    view->displayStrongZombie(strongZombie);
  }
}
