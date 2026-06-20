#include <graphics.h>
#include "enemy.hpp"

Enemy::Enemy(int health, int x, int y) : Opponent(health, x, y) {}

void Enemy::draw() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, radius / 2, radius / 2);

    setcolor(BLACK);
    setbkcolor(RED);
    char str[10];
    sprintf(str, "%d", health);

    int textWidth = textwidth(str);
    int textHeight = textheight(str);

    outtextxy(x - textWidth / 2, y - textHeight / 2, str);
    setbkcolor(WHITE);
}

int Enemy::winnerHp(int playerHp, Opponent& level) {
    if (playerHp > level.health) {
        playerHp += level.health;
    } else {
        playerHp -= level.health;
    }
    return playerHp;
}
