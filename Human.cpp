#include "Human.h"
void Human::performAttack(Character &target) {}

void Human::performDefense(Enemy &attacker) {}

std::string Human::NameMaker()
{
    return "";
}
void Human::takeDamage(){};

void Human::levelUp() {}

int Human::getAge()
{
    return age;
}

void Human::setName(int age)
{
    this->age = age;
}

int Human::getCurrXP()
{
    return currXP;
}

void Human::setCurrXP(int currXP)
{
    this->currXP = currXP;
}

int Human::getMaxXP()
{
    return maxXP;
}

void Human::setMaxXP(int maxXP)
{
    this->maxXP = maxXP;
}

double Human::getStamina()
{
    return stamina;
}

void Human::setStamina(double stamina)
{
    this->stamina = stamina;
}

double Human::getStrength()
{
    return strength;
}

void Human::setStrength(double strength)
{
    this->strength = strength;
}

double Human::getEndurance()
{
    return endurance;
}

void Human::setEndurance(double endurance)
{
    this->endurance = endurance;
}

double Human::getAccuracy()
{
    return accuracy;
}

void Human::setAccuracy(double accuracy)
{
    this->accuracy = accuracy;
}

double Human::getPace()
{
    return pace;
}

void Human::setPace(double pace)
{
    this->pace = pace;
}

double Human::getMind()
{
    return mind;
}

void Human::setMind(double mind)
{
    this->mind = mind;
}

int Human::getCoin()
{
    return coin;
}

void Human::setCoin(int coin)
{
    this->coin = coin;
}

int Human::inventorySize()
{
    return inventory.size();
}

Item *Human::itemsAt(int index)
{
    if (this->inventorySize())
    {
        return inventory.at(index - 1);
    }
    return nullptr;
}

void Human::showInventory()
{
    if (this->inventorySize() > 0)
    {
        for (int i = 0; i < this->inventorySize(); i++)
        {
            cout << i + 1 << ". " << inventory[i] << " X" << inventory[i]->getCount() << endl;
        }
    }
    else
    {
        cout << "Your inventory is empty!" << endl;
    }
}

void Human::addInventory(Item *item)
{
    int check = 0;
    if (this->inventorySize() > 0)
    {
        for (int i = 0; i < this->inventorySize(); i++)
        {
            if (item->getName() == inventory[i]->getName())
            {
                inventory[i]->setCount(inventory[i]->getCount() + 1);
                check++;
                break;
            }
            if (check == 0)
            {
                inventory.push_back(item);
                //  inventory[inventory.size()-1]->setCount(1);
            }
        }
    }
    else
    {
        inventory.push_back(item);
        // inventory[inventory.size()-1]->setCount(1);
    }
}

void Human::removeInventory(int index)
{
    if (index - 1 < this->inventorySize())
    {
        if (inventory[index - 1]->getCount() == 1)
        {
            inventory.erase(inventory.begin() + index);
        }
        else
        {
            inventory[index - 1]->setCount(inventory[index - 1]->getCount() - 1);
        }
    }
}

void Human::addInventory(Item *item, int count)
{
    int check = 0;
    if (this->inventorySize() > 0)
    {
        for (int i = 0; i < this->inventorySize(); i++)
        {
            if (item->getName() == inventory[i]->getName())
            {
                inventory[i]->setCount(inventory[i]->getCount() + count);
                check++;
                break;
            }
            if (check == 0)
            {
                inventory.push_back(item);
                inventory[inventory.size() - 1]->setCount(count);
            }
        }
    }
    else
    {
        inventory.push_back(item);
        inventory[inventory.size() - 1]->setCount(count);
    }
}

void Human::removeInventory(int index, int count)
{
    if (index - 1 < this->inventorySize())
    {
        if (inventory[index - 1]->getCount() == count)
        {
            inventory.erase(inventory.begin() + index);
        }
        else if (inventory[index - 1]->getCount() > count)
        {
            inventory[index - 1]->setCount(inventory[index - 1]->getCount() - count);
        }
        else
        {
            cout << "You hav only " << inventory[index - 1]->getCount() << " " << inventory[index - 1]->getName() << "s you can't remove " << count << endl;
        }
    }
}

Item *Human::getArmor()
{
    return armor;
}

Item *Human::getWeapon()
{
    return weapon;
}

// Item *Human::stringToItem(const std::string &line)
// {
//     Item *item = new ConcreteItem(); 
//     return item;
// }
// we need to add ConcreteItem() because of the item is abstracted class with pure functions;

void Human::setArmor(Item *aromor)
{
    this->armor = armor;
}

void Human::setWeapon(Item *weapon)
{
    this->weapon = weapon;
}
