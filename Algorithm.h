//Algorithm.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include "MazeSearchable.h"

class Algorithm{

    std::string name;

    
    public:
    virtual std::queue<State> solve() = 0;
    Algorithm();
    ~Algorithm();

};




