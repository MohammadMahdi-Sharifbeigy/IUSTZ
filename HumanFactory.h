#ifndef HUMAN_FACTORY_H
#define HUMAN_FACTORY_H

#include "Human.h"
#include "AsianMom.h"
#include "Assassin.h"
#include "Cyborg.h"
#include "Paladin.h"
#include "SuperHero.h"
#include "Sniper.h"
#include "Wizard.h"

class HumanFactory : public Human {
public:
    static Human* createHuman(characterType type, const string& name, int age, double hp, double attack, double defense, int coin) {
        switch (type) {
            case PALADIN:
                return new Paladin(name, age, hp, defense, attack, type, coin);
                break;
            case SUPERHERO:
                return new SuperHero(name, age, hp, defense, attack, type, coin);
                break;
            case ASSASSIN:
                return new Assassin(name, age, hp, defense, attack, type, coin);
                break;
            case ASIANMOM:
                return new AsianMom(name, age, hp, defense, attack, type, coin);
                break;
            case CYBORG:
                return new Cyborg(name, age, hp, defense, attack, type, coin);
                break;
            case SNIPER:
                return new Sniper(name, age, hp, defense, attack, type, coin);
                break;
            case WIZARD:
                return new Wizard(name, age, hp, defense, attack, type, coin);
                break;
            default:
                return nullptr;
        }
    }
};

#endif  // HUMAN_FACTORY_H
