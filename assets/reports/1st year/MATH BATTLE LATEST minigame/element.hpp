#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Element 
{
// protected:
//     int health;

public:
int health;
    Element(int health) : health(health) {}

    virtual void draw() = 0;
};

#endif
