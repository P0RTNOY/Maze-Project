//State.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415

#pragma once
#include <iostream>
using namespace std;



class Maze2d;

class State{
    int x;
    int y;
    State* m_cameFrom;
    

    public:
    State();
    State(int posX, int posY, State * cameFrom);
    State(const State& other);
    ~State();
    int getX() const;
    int getY() const;
    const State* getCameFrom(){return m_cameFrom;}

   State& operator=(const State& other)
   {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            m_cameFrom = other.m_cameFrom;
        }
        return *this;
   }
    
 bool operator<(const State& other) const {
        // Compare based on some criteria, for example, comparing x and y coordinates
        return std::tie(x, y) < std::tie(other.x, other.y);
    }

    bool operator>(const State& other) const {
        // Compare based on some criteria, for example, comparing x and y coordinates
        return std::tie(x, y) > std::tie(other.x, other.y);
    }



};