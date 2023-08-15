//BFS.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "BFS.h"


// BFS::BFS(MazeSearchable *maze){
//     std::cout << "BFS CONSTRUCTOR" << std::endl;
//     m_board = maze->getBoard();
//     m_start = maze->getStartState();
//     m_end = maze->getGoalState();
// }

BFS::BFS(const State *start,const  State *end, std::vector<std::vector<int>> board){
    m_start = start;
    m_end = end;
    m_board = board;
}

bool BFS::isValid(int row, int col) {
    return row >= 0 && row < m_board.size() && col >= 0 && col < m_board[0].size() && m_board[row][col] == 0;
}
std::queue<State*> BFS::solve() {
    std::queue<State*> q;
    std::vector<std::vector<bool>> visited(m_board.size(), std::vector<bool>(m_board[0].size(), false));

    q.push(const_cast<State*>(m_start));  // Use const_cast to remove the const qualifier
    visited[m_start->getX()][m_start->getY()] = true;

    while (!q.empty()) {
        State* currentState = q.front();
        q.pop();
        if (currentState->getX() == m_end->getX() && currentState->getY() == m_end->getY()) {
            std::cout << "Maze solved!" << std::endl;
            // Replace with constructPath logic
            
            return q;  // Return the path or solution
        }

        // Explore neighboring states (up, down, left, right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int dir = 0; dir < 4; ++dir) {
            int newRow = currentState->getX() + dx[dir];
            int newCol = currentState->getY() + dy[dir];

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                State* newState = new State(newRow, newCol, currentState);
                q.push(newState);
            }
        }
    }

    std::cout << "Maze cannot be solved!" << std::endl;
    return std::queue<State*>();  // Return an empty queue
}




//      std::queue<State> BFS::solve() {
//     std::queue<State> q;
//     std::vector<std::vector<bool>> visited(m_board.size(), std::vector<bool>(m_board[0].size(), false));

//     q.push(m_start);
//     visited[m_start.getX()][m_start.getY()] = true;

//     while (!q.empty()) {
//         std::cout<<"heyyyyyyyyyyyy"<<std::endl;
//         State currentState = q.front();
//         q.pop();

//         if (currentState.getX() == m_end.getX() && currentState.getY() == m_end.getY()) {
//             std::cout << "Maze solved!" << std::endl;
//             return q;
//         }

//         for (const auto& moveState : m_maze.possibleMoves(currentState)) {
//             int newRow = moveState.getX();
//             int newCol = moveState.getY();

//             if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
//                 visited[newRow][newCol] = true;
//                 q.push(moveState);
//             }
//         }
//     }

//     std::cout << "Maze cannot be solved!" << std::endl;
// }




