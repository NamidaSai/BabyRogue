#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item {
    public:
        Item();
        void SetValues();

    private:
        int attack;
        int defense;
        int health;
        int cost;
        bool consumable;
 



};

#endif /*ITEM_H*/