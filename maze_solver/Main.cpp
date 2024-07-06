#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>

#include "API.h"

void log(const std::string& text) {
    std::cerr << text << " Nego🐲 " << std::endl;
}

enum Direction { NORTH, EAST, SOUTH, WEST };

// Helper functions to manage the robot's direction and movements
Direction currentDirection = NORTH;

void turnTo(Direction newDirection) {
    int leftTurns = (currentDirection - newDirection + 4) % 4;
    int rightTurns = (newDirection - currentDirection + 4) % 4;

    if (leftTurns <= rightTurns) {
        for (int i = 0; i < leftTurns; i++) {
            API::turnLeft();
        }
    } else {
        for (int i = 0; i < rightTurns; i++) {
            API::turnRight();
        }
    }

    currentDirection = newDirection;
}


bool isWallInDirection(Direction dir) {
    if (dir == currentDirection) return API::wallFront();
    if (dir == static_cast<Direction>((currentDirection + 1) % 4)) return API::wallRight();
    if (dir == static_cast<Direction>((currentDirection + 3) % 4)) return API::wallLeft();
    return true; // Should never reach here
}

void moveInDirection(Direction dir) {
    turnTo(dir);
    API::moveForward();
}

Direction oppositeDirection(Direction dir) {
    return static_cast<Direction>((dir + 2) % 4);
}

struct Cell {
    int x, y;
    Direction dir;
    Cell(int _x, int _y, Direction _dir) : x(_x), y(_y), dir(_dir) {}
};

void DFS(int startX, int startY) {
    int width = API::mazeWidth();
    int height = API::mazeHeight();
    std::vector<std::vector<bool>> visited(width, std::vector<bool>(height, false));
    std::stack<Cell> stack;

    stack.push(Cell(startX, startY, NORTH));
    visited[startX][startY] = true;

    while (!stack.empty()) {
        Cell current = stack.top();
        stack.pop();

        int x = current.x;
        int y = current.y;

        log("Visiting cell: (" + std::to_string(x) + ", " + std::to_string(y) + ")");
        API::setColor(x, y, 'G');

        Direction directions[] = {NORTH, EAST, SOUTH, WEST};
        bool foundUnvisited = false;

        for (Direction dir : directions) {
            int newX = x, newY = y;
            if (dir == NORTH) newY++;
            else if (dir == EAST) newX++;
            else if (dir == SOUTH) newY--;
            else if (dir == WEST) newX--;

            if (newX >= 0 && newX < width && newY >= 0 && newY < height && !visited[newX][newY]) {
                if (!isWallInDirection(dir)) {
                    stack.push(Cell(x, y, dir)); // Push current cell for backtracking
                    moveInDirection(dir);
                    currentDirection = dir;
                    stack.push(Cell(newX, newY, dir));
                    visited[newX][newY] = true;
                    foundUnvisited = true;
                    break; // Move to the next cell immediately
                }
            }
        }

        if (!foundUnvisited) {
            log("Backtracking from: (" + std::to_string(x) + ", " + std::to_string(y) + ")");
            if (!stack.empty()) {
                Cell backtrack = stack.top();
                moveInDirection(oppositeDirection(backtrack.dir));
                currentDirection = oppositeDirection(backtrack.dir);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    log("Running...");
    API::setColor(0, 0, 'G');
    API::setText(0, 0, "Start");

    DFS(0, 0);

    return 0;
}
