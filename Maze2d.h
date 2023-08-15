//Maze2d.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <iostream>
#include <memory>
#include "Solution.h"
#include "State.h"
#include "Data.h"
#include "Maze2dGenerator.h"

class Data;

class Maze2d{
private:
    std::string m_name;
    std::vector<std::vector<int> > m_board;
    const State* m_start;  // Use shared_ptr
    const State* m_end;    // Use shared_ptr
    bool m_isSolved;
    const Solution *m_solution;
    Data* m_content;

public:
    Maze2d();
    Maze2d(const std::string& name, std::vector<std::vector<int> > board, State* start, State* end, bool isSolved, const Solution *solution, Data* content);
         Maze2d(std::string maze_name, const Data* content);
        ~Maze2d(){
        delete m_start;
        delete m_end;
        delete m_solution;
        delete m_content;
    }
    Maze2d(const Maze2d& other)
    {
        m_name = other.m_name;
        m_board = other.m_board;
        m_start = other.m_start;
        m_end = other.m_end;
        m_isSolved = other.m_isSolved;
        m_solution = other.m_solution;
        m_content = other.m_content;
    }
    
    const string getName(){return m_name;}
    const State* getStart() { return m_start; }
    const State *getEnd(){return m_end;}
    std::vector<std::vector<int> > getBoard(){return m_board;}
    Data* getData();
    std::vector<State> possibleMoves(State p);
    void setSolved(bool val){
        m_isSolved = val;
    };
    const Solution* getSolution() { return m_solution; }

 void print() {
    int newSize = m_board.size();
    if (newSize == 0) {
        return;  // Handle the case when m_board is empty
    }

    std::cout << this->getStart()->getX();
    std::cout << this->getStart()->getY() << std::endl;

    std::cout << this->getEnd()->getX();
    std::cout << this->getEnd()->getY() << std::endl;

    // Set start and end positions on the maze board
    m_board[this->getStart()->getX()][this->getStart()->getY()] = 5;
    m_board[this->getEnd()->getX()][this->getEnd()->getY()] = 9;

    for (int row = 0; row < newSize; ++row) {
        for (int col = 0; col < newSize; ++col) {
            if (row == 0 || row == newSize - 1 || col == 0 || col == newSize - 1) {
                std::cout << " - ";
            } else if (m_board[row][col] == 0) {
                std::cout << "   ";
            } else if (m_board[row][col] == 1) {
                std::cout << " * ";
            }if (m_board[row][col] == 5) {
                std::cout << " S ";
            }if (m_board[row][col] == 9) {
                std::cout << " E ";
            }
        }
        std::cout << std::endl;
    }
}

void addSolution(Solution* sol)
    {
        m_isSolved = true;
        m_solution = sol;
    }




  
    



};

