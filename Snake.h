#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "definitions.h"

class Snake {
private:
    std::deque<Point> body; // save snake body
    Direction direction;

public:
    Snake(int startX, int startY); // cons

    void move();
    void grow();
    bool checkCollision(int width, int height) const; 

    std::deque<Point> getBody() const;
    Point getHead() const;

    void setDirection(Direction newDir);
    Direction getDirection() const;
};

#endif 