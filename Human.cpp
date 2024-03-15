#include "Human.h"

void Human::takeDamage(int damage) {}

void Human::performAttack(Character &target) {}

void Human::performDefense(Enemy &attacker) {}

std::string Human::NameMaker() {
    return "";
}

void Human::levelUp() {}

int Human::getAge() {
    return age;
}

void Human::setName(int age) {
    this->age = age;
}

int Human::getCurrXP() {
    return currXP;
}

void Human::setCurrXP(int currXP) {
    this->currXP = currXP;
}

int Human::getMaxXP() {
    return maxXP;
}

void Human::setMaxXP(int maxXP) {
    this->maxXP = maxXP;
}

double Human::getStamina() {
    return stamina;
}

void Human::setStamina(double stamina) {
    this->stamina = stamina;
}

double Human::getStrength() {
    return strength;
}

void Human::setStrength(double strength) {
    this->strength = strength;
}

double Human::getEndurance() {
    return endurance;
}

void Human::setEndurance(double endurance) {
    this->endurance = endurance;
}

double Human::getAccuracy() {
    return accuracy;
}

void Human::setAccuracy(double accuracy) {
    this->accuracy = accuracy;
}

double Human::getPace() {
    return pace;
}

void Human::setPace(double pace) {
    this->pace = pace;
}

double Human::getMind() {
    return mind;
}

void Human::setMind(double mind) {
    this->mind = mind;
}

int Human::getCoin() {
    return coin;
}

void Human::setCoin(int coin) {
    this->coin = coin;
}
