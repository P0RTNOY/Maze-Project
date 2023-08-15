//Data.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "Data.h"
#include "State.h"

Data::Data() : m_start(nullptr), m_end(nullptr), m_board() {}

Data::Data(Maze2d *maze)
{
    m_start = maze->getStart();
    m_end = maze->getEnd();
    m_board = maze->getBoard();
}

Data::Data(const State* start, const State* end, std::vector<std::vector<int>> board)
    : m_start(start), m_end(end), m_board(board) {}

Data::~Data() {
    // You should delete the dynamically allocated State objects here if needed
    delete m_start;
    delete m_end;
}


