//Astar.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "Astar.h"



Astar::Astar(const State *start, const State *end, std::vector<std::vector<int>> board){
    m_start = start;
    m_end = end;
    m_board = board;
}
bool Astar::isValid(int row, int col) {
    return row >= 0 && row < m_board.size() && col >= 0 && col < m_board[0].size() && m_board[row][col] == 0;
}

int Astar::heuristic(const State *start,const State *end) {
    // A* heuristic function (Manhattan distance)
    return std::abs(start->getX() - end->getX() + (start->getY() - end->getY()));
}

std::queue<State*> Astar::solve() {
    std::priority_queue<State, std::vector<State>, std::greater<State>> openSet;
    std::vector<std::vector<bool>> visited(m_board.size(), std::vector<bool>(m_board[0].size(), false));
     std::queue<State*> solutionSteps;
            State backtrackState;   
            

    openSet.push(*m_start);
    visited[m_start->getX()][m_start->getY()] = true;

    while (!openSet.empty()) {
        State currentState = openSet.top();
        openSet.pop();

        if (currentState.getX() == m_end->getX() && currentState.getY() == m_end->getY()) {
            std::cout << "Maze solved!" << std::endl;
            backtrackState   = currentState;
            while (backtrackState.getCameFrom() != nullptr) {
                solutionSteps.push(new State(backtrackState));
                backtrackState = *(backtrackState.getCameFrom());
            }
            // std::cout<<"!!!helloo!!!"<<std::endl;
            return solutionSteps ;
        }

        for (const auto& moveState : possibleMoves(currentState)) {
            int newRow = moveState.getX();
            int newCol = moveState.getY();

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                openSet.push(moveState);
            }
        }
    }

   std::cout << "Maze cannot be solved!" << std::endl;
    return std::queue<State*>();  // Return an empty queue
}
