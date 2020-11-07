#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item {
    public:
        Item();
        

    private:
        int attack;
        int defense;
        int health;
        int cost;
        bool consumable;
        void SetValues();



};

#endif /*ITEM_H*/