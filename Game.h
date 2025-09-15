#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "definitions.h"

class Game {
private:
    int width, height;
    int score;
    bool gameOver;
    Snake snake;
    Point food;

    void generateFood();
    void draw();
    void processInput();
    void updateLogic();

public:
    Game(int w, int h);
    void run(); 
};

#endif 