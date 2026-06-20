#include <graphics.h>
#include "player.hpp"

Player::Player(int health) : Element(health), x(100), y(200), radius(50) {}

void Player::draw() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, radius/2 , radius/2);
    
    setcolor(BLACK);
    setbkcolor(YELLOW);  // Set the background color of the text to match the circle
    char str[10];
    sprintf(str, "%d", health);
    
    int textWidth = textwidth(str);
    int textHeight = textheight(str);
    
    outtextxy(x - textWidth / 2, y - textHeight / 2, str);

    setbkcolor(WHITE);
}
