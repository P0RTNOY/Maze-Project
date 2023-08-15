//Astar.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <iostream>
#include "State.h"
#include <vector>
#include <queue>
#include <algorithm>  // For std::sort
#include <cmath>      // For std::abs

class Astar{
private:
    std::vector<std::vector<int>> m_board;
    const State *m_start;  
    const State *m_end;

public:
    Astar(){};
    Astar(const State *start, const State *end, std::vector<std::vector<int>> board);
    bool isValid(int row, int col);
    int heuristic(const State *start,const State *end);  // A* heuristic function

    std::queue<State*> solve();

    std::vector<State> possibleMoves(State p) {
    int x = p.getX();
    int y = p.getY();
    std::vector<State> moves;
    // Check if moving down is possible
    if (x + 1 < m_board.size() && m_board[x + 1][y] == 0) {
        moves.push_back(State(x + 1, y, nullptr));
    }
    // Check if moving up is possible
    if (x - 1 >= 0 && m_board[x - 1][y] == 0) {
        moves.push_back(State(x - 1, y, nullptr));
    }
    // Check if moving right is possible
    if (y + 1 < m_board[0].size() && m_board[x][y + 1] == 0) {
        moves.push_back(State(x, y + 1, nullptr));
    }
    // Check if moving left is possible
    if (y - 1 >= 0 && m_board[x][y - 1] == 0) {
        moves.push_back(State(x, y - 1, nullptr));
    }
    return moves;
}
};
