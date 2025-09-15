#include "Snake.h"

Snake::Snake(int startX, int startY) {
    direction = Direction::STOP;
    body.push_front({startX, startY}); 
}

void Snake::move() {
    if (direction == Direction::STOP) return;

    Point newHead = getHead(); 

    switch (direction) {
        case Direction::LEFT:  newHead.x--; break;
        case Direction::RIGHT: newHead.x++; break;
        case Direction::UP:    newHead.y--; break;
        case Direction::DOWN:  newHead.y++; break;
    }

    body.push_front(newHead); 
    body.pop_back();          
}

void Snake::grow() {
    
    body.push_back(body.back()); 
}

bool Snake::checkCollision(int width, int height) const {
    Point head = getHead();

    if (head.x >= width || head.x < 0 || head.y >= height || head.y < 0) {
        return true;
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (head == body[i]) {
            return true;
        }
    }

    return false;
}

std::deque<Point> Snake::getBody() const { return body; }
Point Snake::getHead() const { return body.front(); }
Direction Snake::getDirection() const { return direction; }

void Snake::setDirection(Direction newDir) {
    if (direction == Direction::UP && newDir == Direction::DOWN) return;
    if (direction == Direction::DOWN && newDir == Direction::UP) return;
    if (direction == Direction::LEFT && newDir == Direction::RIGHT) return;
    if (direction == Direction::RIGHT && newDir == Direction::LEFT) return;
    direction = newDir;
}