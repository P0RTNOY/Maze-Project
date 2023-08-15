//Solution.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "Solution.h"
#include "State.h"

Solution::Solution() {
    m_solution.push_back(nullptr);
}


    // Solution::Solution(const Solution& other) {
    //     m_solution = other.m_solution;
    // }


    Solution::~Solution() {
    for (auto statePtr : m_solution) {
        delete statePtr;
    }
    m_solution.clear();
}
    









