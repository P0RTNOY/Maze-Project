//BFS.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <iostream>
#include <vector>
#include <queue>
// #include "Algorithm.h"
#include "State.h"
// #include "MazeSearchable.h"





class BFS{
private:
    std::vector<std::vector<int>> m_board;
    const State *m_start;  
    const State *m_end;    

public:
    BFS(){};
    // BFS(MazeSearchable *search){
    //     m_start = search->getStartState();
    //     m_end = search->getGoalState();
    //     m_board = search->getBoard();
    // };
    BFS(const State *start,const  State *end, std::vector<std::vector<int> > board);
    bool isValid(int row, int col);
    virtual std::queue<State*> solve();

};
