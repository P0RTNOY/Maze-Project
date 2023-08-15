//Solution.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <iostream>
#include <vector>
#include "State.h"


class Solution{
    std::vector<State*> m_solution;

public:
    Solution();
    // Solution(const Solution& other);
    ~Solution();
      
    void print() const{
        for(const State* statePtr : m_solution){
            std::cout << statePtr->getX() << " " << statePtr->getY() << std::endl;
        }
    }

    Solution(std::vector<State*> state)
    {
        m_solution = state;
    }

    const Solution& operator=(const Solution& other) {
        if (this != &other) {
            // Clear current solution
            for (auto statePtr : m_solution) {
                delete statePtr;
            }
            m_solution.clear();
            
            // Copy the State pointers as in the copy constructor
            for (const auto& statePtr : other.m_solution) {
                m_solution.push_back(new State(*statePtr));
            }
        }
        return *this;
    }

 Solution(const Solution& other) {
        if (this != &other) {
            // Clear current solution
            for (auto statePtr : m_solution) {
                delete statePtr;
            }
            m_solution.clear();
            
            // Copy the State pointers as in the copy constructor
            for (const auto& statePtr : other.m_solution) {
                m_solution.push_back(new State(*statePtr));
            }
        }
    }


    void addState(const State* state) {
        // Create a copy of the State object and add it to the vector
        m_solution.push_back(new State(*state));
    }

    const std::vector<State*>& getSolution() const {
        return m_solution;
    }


};


