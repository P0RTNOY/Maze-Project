//Maze2dGenerator.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "string"
#include "Maze2d.h"



// enum cell{
//     empty,
//     wall,
//     visited
// };

class Maze2d;

class Maze2dGenerator{
    
    int m_time;

    public:
    Maze2dGenerator() : m_time(0) {}
   virtual Maze2d Generate(const std::string& name) = 0;
    virtual ~Maze2dGenerator() {}

    int getTime() const { return m_time; }


};
