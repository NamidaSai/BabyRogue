#ifndef CHEST_H
#define CHEST_H

class Chest
{
    public:
        Chest();
        Chest(int amount)
        : money_(amount) {}

        int GetX();
        int GetY();
        int GetMoney() { return money_; }

        void SetPosition(int x, int y)
        {
            x_ = x;
            y_ = y;
        }

    private:
        int money_ = 50;
        int x_;
        int y_;
};

#endif /* CHEST_H */