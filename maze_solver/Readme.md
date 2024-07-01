# Robot Maze Solver

This project implements a depth-first search (DFS) algorithm for navigating a robot through a maze. The robot is controlled using an API that provides functions for movement and wall detection.

# Overview
The Robot Maze Solver is designed to control a robot navigating through a maze using a depth-first search (DFS) algorithm. The primary goal is for the robot to visit every cell in the maze by making decisions based on its surroundings.

# Dependencies
This project requires the following:

C++ compiler
API for controlling the robot (API.h)
Ensure API.h is correctly included and configured in your project.

# Code Structure
main.cpp: Contains the main function and the DFS implementation.
API.h: Header file for the robot control API.


# Functions
log(const std::string& text)
Logs messages to the standard error stream with a custom tag.

turnTo(Direction newDirection)
Turns the robot to face the specified direction.

isWallInDirection(Direction dir)
Checks if there is a wall in the specified direction relative to the robot's current direction.

moveInDirection(Direction dir)
Moves the robot in the specified direction.

oppositeDirection(Direction dir)
Returns the direction opposite to the specified direction.

DFS(int startX, int startY)
Implements the depth-first search algorithm to navigate the maze from the starting cell (startX, startY).

main(int argc, char* argv[])
Entry point of the program. Initializes the maze navigation and starts the DFS.

# Notes
The maze is represented as a grid with width and height obtained from the API.
The robot starts at the position (0, 0) and marks the start cell with green color using API::setColor(0, 0, 'G').
The DFS algorithm explores each cell, marks it as visited, and backtracks if no unvisited neighboring cells are found.
Make sure the API functions (turnRight, moveForward, wallFront, wallRight, wallLeft, setColor, setText, mazeWidth, mazeHeight) are implemented as per the requirements.