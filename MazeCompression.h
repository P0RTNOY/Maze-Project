//MazeCompression.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415

#pragma once
#include "Maze2d.h"


class MazeCompression :public Maze2d{
    int *CompressedMaze;

    public:
    MazeCompression(Maze2d maze);
    ~MazeCompression();
};

