//SimpleMaze2dGenerator.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "string"
#include "Maze2dGenerator.h"




class SimpleMaze2dGenerator :public Maze2dGenerator{
    
    
    public:
    Maze2d Generate(const std::string& name) override;

};

