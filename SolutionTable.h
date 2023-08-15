//SolutionTable.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <unordered_map>
#include <functional>
#include "Solution.h" // Include Solution class definition

class SolutionTable :public Solution{
private:
    std::unordered_map<std::string,Solution*> solutionHashtable; // Hashtable for Solution objects

public:
    SolutionTable();
    void addSolution(const std::string& mazeId, const Solution& solution);
    Solution getSolution(const std::string& mazeId);

    
};

