#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include "player.hpp"
#include "enemy.hpp"
#include "loot.hpp"
#include "background.hpp"

#define MAX 5
Opponent *opp[MAX];

void generateListOfShape() {
    int y = 100;
    int health = 10 + rand() % 10;
    opp[0] = new Loot(health, 600, y);
    y += 150;
    for(int i = 1;  i < MAX; i++) {
        int side = rand() % 2;
        if (side == 0) {
            int health = 5 + rand() % 10;
            opp[i] = new Enemy(health, 600, y);
        } else {
            int health = 10 + rand() % 10;
            opp[i] = new Loot(health, 600, y); 
        }
        y += 150;
    }
}

int gameJourney(int playerHp)
{
    Background bg;

    if (GetAsyncKeyState(VK_LBUTTON)) {
            int x = mousex();
            int y = mousey();

            for (int i = 0; i < MAX; i++) {
                if (opp[i] != nullptr) {
                    int dx = x - opp[i]->x;
                    int dy = y - opp[i]->y;
                    if (dx * dx + dy * dy <= opp[i]->radius * opp[i]->radius) {
                        playerHp = opp[i]->winnerHp(playerHp, *opp[i]);

                        if (playerHp <= 0) {
                            bg.displayGameOver("lose.jpg");
                            getch();
                            closegraph();
                            exit(0);
                        } else {
                            delete opp[i];
                            opp[i] = nullptr;
                            break;
                        }
                    }
                }
            }
    }
    return playerHp;
}

int main() {
    int width = getmaxwidth();
    int height = getmaxheight();
    initwindow(width, height, "MATH BATTLE");

    srand(time(0));

    Background bg;
    bg.displayBackground("bg.jpg");

    generateListOfShape();

    Player player(5);
    player.draw();

    for(int i = 0; i < MAX; i++) {
        opp[i]->draw();
    }

    while (true) {
        for(int i=0; i<5; i++)
        {
            player.health = gameJourney(player.health);
            
            bg.displayBackground("bg.jpg");
            player.draw();
            for(int k = 0; k < MAX; k++) {
                if (opp[k] != nullptr) {
                    opp[k]->draw();
                }
            }
        }
            
        if (player.health <= 0) {
                bg.displayGameOver("lose.jpg");
                break;
        } else {
        bool allNull = true;
            for(int i = 0; i < MAX; i++) {
                if (opp[i] != nullptr) {
                    allNull = false;
                    break;
                }
            }
            if (allNull) {
                bg.displayYouWin("win.jpg");
                break;
            }
        }

        delay(100);
    }

    getch();
    closegraph();
    return 0;
}