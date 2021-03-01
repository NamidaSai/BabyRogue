#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
    public:
        //Item(int choice);
        //Item();
        void SetValues(int choice);
        string GetName() { return name; }
        int GetAttack() { return attack; }
        int GetDefense() { return defense; }
        int GetHealth() { return health; }
        int GetCost() { return cost; }
        bool GetConsumable() { return consumable; }

    private:
        string name;
        int attack;
        int defense;
        int health;
        int cost;
        bool consumable;
        
 



};

#endif /*ITEM_H*/