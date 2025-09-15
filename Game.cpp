#include "Game.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   

#include <conio.h>
#include <windows.h>

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

Game::Game(int w, int h)
    : width(w), height(h), score(0), gameOver(false), snake(w / 2, h / 2) {
    srand(time(NULL)); 
    HideCursor();
    generateFood();
}

void Game::generateFood() {
    bool onSnake;
    do {
        onSnake = false;
        food.x = rand() % width;
        food.y = rand() % height;
        for (const auto& segment : snake.getBody()) {
            if (food == segment) {
                onSnake = true;
                break;
            }
        }
    } while (onSnake);
}

void Game::run() {
    while (!gameOver) {
        draw();
        processInput();
        updateLogic();
        Sleep(100); 
    }
    system("cls");
    std::cout << "\n\n\t\tGAME OVER!\n";
    std::cout << "\t\tYour Score: " << score << std::endl;
}

void Game::processInput() {
    if (_kbhit()) { 
        switch (_getch()) { 
            case 'w': snake.setDirection(Direction::UP); break;
            case 'a': snake.setDirection(Direction::LEFT); break;
            case 's': snake.setDirection(Direction::DOWN); break;
            case 'd': snake.setDirection(Direction::RIGHT); break;
            case 'x': gameOver = true; break;
        }
    }
}

void Game::updateLogic() {
    snake.move();

    if (snake.checkCollision(width, height)) {
        gameOver = true;
        return;
    }

    if (snake.getHead() == food) {
        score += 10;
        snake.grow();
        generateFood();
    }
}

void Game::draw() {
    system("cls"); 
    for (int i = 0; i < width + 2; i++) std::cout << "#";
    std::cout << std::endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0) std::cout << "#"; 

            Point currentPoint = {x, y};
            bool isSnakeBody = false;

            for(const auto& segment : snake.getBody()){
                if(currentPoint == segment){
                    if(currentPoint == snake.getHead()) std::cout << "O";
                    else std::cout << "o";
                    isSnakeBody = true;
                    break;
                }
            }
            
            if(isSnakeBody) continue;

            if (currentPoint == food) {
                std::cout << "F";
            } else {
                std::cout << " ";
            }

            if (x == width - 1) std::cout << "#"; 
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) std::cout << "#";
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}