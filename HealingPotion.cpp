#include <iostream>
#include "HealingPotion.h"

using namespace std;

void HealingPotion::increaseHP(chara &target){
    cout<<"hi its going to be ok";
}
HealingPotion::HealingPotion(string name, double price, bool vIP, double potency):Consumable(name, price, vIP, potency){

}