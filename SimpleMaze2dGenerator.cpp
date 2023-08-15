//SimpleMaze2dGenerator.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "SimpleMaze2dGenerator.h"
#include <cstdlib> 
#include <ctime>

Maze2d SimpleMaze2dGenerator::Generate(const std::string& name) {
    srand(time(nullptr)); 
    int numRows = rand() % 10 + 10; // 
    int numCols = numRows; 

    // Create a random maze board with the specified number of rows and columns
    std::vector<std::vector<int>> randomBoard(numRows, std::vector<int>(numCols, 0));

    // Place the start and end points on the frame
    State* start = new State(1, 1, nullptr); // Assuming State constructor takes (x, y, cameFrom)
    State* end = new State(numRows - 2, numCols - 2, nullptr);

    // Set random walls in the maze
    for (int row = 1; row < numRows; ++row) {
        for (int col = 1; col < numCols; ++col) {
            // if (row == 1 || row == numRows - 1 || col == 1 || col == numCols - 1) {
            //     // Set the frame as walls
            //     randomBoard[row][col] = 1;
            // } else {
            //     // Set random walls (20% probability)
                if (rand() % 100 < 20) {
                    randomBoard[row][col] = 1;
                } else {
                    randomBoard[row][col] = 0; // Open path
                    
                }
        //     }
        }
     
    }
   std::cout<<endl;
    // Create a Data object with the generated start, end, and board
    Data* content = new Data(start, end, randomBoard);

    // Create and return the Maze2d using the Data object
    Maze2d generatedMaze(name, content);
    std::cout<< "Generation complete"<<std::endl;
    std::cout<<endl;
    return generatedMaze;
}
