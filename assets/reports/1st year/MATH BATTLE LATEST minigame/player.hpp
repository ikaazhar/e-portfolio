#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "element.hpp"

class Player : public Element {
public:
    int x, y, radius;

    Player(int health);
    void draw() override;
};

#endif
