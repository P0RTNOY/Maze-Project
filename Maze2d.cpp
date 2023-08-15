//Maze2d.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "Maze2d.h"
#include <memory>
#include <vector>

// Maze2d::Maze2d(std::string name, std::vector<std::vector<int> > board, State* start, State* end, bool isSolved, Solution *solution, Data* content)
//     : m_name(name), m_board(board), m_start(start), m_end(end), m_isSolved(isSolved), m_solution(solution), m_content(content) {
// }


Maze2d::Maze2d(const std::string& name, std::vector<std::vector<int> > board, State* start, State* end, bool isSolved, const Solution* solution, Data* content)
{
    m_name = name;
    m_board = board;
    m_start = start;
    m_end = end;
    m_isSolved = isSolved;
    m_solution = solution;
    m_content = content;
}

Maze2d::Maze2d(std::string maze_name, const Data* content)
{
    m_name = maze_name;
    m_start = content->getStart();
    m_end = content->getEnd();
    m_board = content->getBoard();
}
Maze2d::Maze2d()
{
    m_name = "MyMaze";
    m_board = {};
    m_start = new State();
    m_end = new State();
    m_isSolved = false;
    m_solution = new Solution();
    m_content = new Data();

}
  

std::vector<State> Maze2d::possibleMoves(State p) {
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


