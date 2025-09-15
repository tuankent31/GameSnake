#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// save coor
struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

enum class Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

#endif 