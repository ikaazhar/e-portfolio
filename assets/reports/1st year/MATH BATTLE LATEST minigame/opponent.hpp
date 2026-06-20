#ifndef OPPONENT_HPP
#define OPPONENT_HPP

#include "element.hpp"

class Opponent : public Element {
public:
    int x, y, radius;

    Opponent(int health, int x, int y);
    virtual void draw() override = 0;
    virtual int winnerHp(int playerHp, Opponent& level) = 0;
};

#endif
