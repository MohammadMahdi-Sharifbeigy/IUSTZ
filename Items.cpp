#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
    string Name;
    double Price;
    int Damage;
    double Defanse;
    bool VIP;

public:
    string GetName()
    {
        return Name;
    }
    double GetPricee()
    {
        return Price;
    }
    int GetDamage()
    {
        return Damage;
    }
    double GetDefense()
    {
        return Defanse;
    }
    bool isVIP()
    {
        return VIP;
    }
    void PickForFight();
    Item(string name, double price, int damage, double defense, bool vip)
    {
        Name = name;
        Price = price;
        Damage = damage;
        Defanse = defense;
        VIP = vip;
    }
};