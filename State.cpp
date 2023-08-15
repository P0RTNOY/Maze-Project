//Stage.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "State.h"




State::State()
{
    x = 1;
    y = 1;
    m_cameFrom  = nullptr;
 
}


State::State(int posX, int posY, State* cameFrom): x(posX), y(posY), m_cameFrom(cameFrom) {
}



State::State(const State& other)
{
    x = other.x;
    y = other.y;
    m_cameFrom = other.m_cameFrom;
}

State::~State() {
}

int State::getX() const {
    return x;
}

int State::getY() const {
    return y;
}



