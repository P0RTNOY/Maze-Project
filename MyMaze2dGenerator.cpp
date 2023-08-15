//MyMaze2dGenerator.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415

#include "MyMaze2dGenerator.h"
#include "Maze2d.h"
#include "State.h"

Maze2d MyMaze2dGenerator::Generate(const std::string& name) {
    // Define the size of the maze
    int mazeSize = 10; // You can adjust the size as needed

    // Create a maze board with walls
    std::vector<std::vector<int>> board(mazeSize, std::vector<int>(mazeSize, 1));

    // Set the paths using an iterative algorithm
    for (int row = 1; row < mazeSize - 1; row += 2) {
        for (int col = 1; col < mazeSize - 1; col += 2) {
            board[row][col] = 0; // Open path
        }
    }

    // Place the start and end points
    State* start = new State(0, 0, nullptr);
    State* end = new State(mazeSize - 1, mazeSize - 1, nullptr);

    // Create a Data object with the generated start, end, and board
    Data* content = new Data(start, end, board);

    // Create and return the Maze2d using the Data object
    Maze2d generatedMaze(name, content);
    return generatedMaze;
}
