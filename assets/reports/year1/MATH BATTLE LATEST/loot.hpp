#ifndef LOOT_HPP
#define LOOT_HPP

#include "opponent.hpp"

class Loot : public Opponent {
public:
    Loot(int health, int x, int y);
    void draw() override;
    int winnerHp(int playerHp, Opponent& level) override;
};

#endif
