#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "opponent.hpp"

class Enemy : public Opponent {
public:
    Enemy(int health, int x, int y);
    void draw() override;
    int winnerHp(int playerHp, Opponent& level) override;
};

#endif
