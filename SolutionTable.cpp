//SolutionTable.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "SolutionTable.h"

SolutionTable::SolutionTable() {
    // Initialize SolutionTable class members if needed
}

void SolutionTable::addSolution(const std::string& mazeId, const Solution& solution) {
    solutionHashtable[mazeId] = new Solution(solution);
}

Solution SolutionTable::getSolution(const std::string& mazeId) {
    if (solutionHashtable.find(mazeId) != solutionHashtable.end()) {
        // return solutionHashtable[mazeId];
        return *solutionHashtable.at(mazeId);
    }
    // You might return a default Solution object or throw an exception here
}
