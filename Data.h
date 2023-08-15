// Data.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <vector>
#include <memory>
#include "Maze2d.h"

class Maze2d;
class State;  // Forward declaration


class Data {
    const State *m_start;
    const State *m_end;
    // std::pair<int,int> m_size;
    std::vector<std::vector<int> > m_board;

public:
    Data(Maze2d *maze);
    Data(const State* start,const State* end,std::vector<std::vector<int> > board);
    Data();
    ~Data();

    const State* getStart() const { return m_start; }
    const State* getEnd() const { return m_end; }
    const std::vector<std::vector<int>>& getBoard() const { return m_board; }


    Data& operator=(const Data& other) {
        if (this != &other) {
            m_start = other.m_start;
            m_end = other.m_end;
            // m_size = other.m_size;
            m_board = other.m_board;
        }
        return *this;
    }
};





