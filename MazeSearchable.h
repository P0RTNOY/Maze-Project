//MazeSearchable.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
using namespace std;
#include "Maze2dGenerator.h"
#include <queue>
#include "BFS.h"
#include "Astar.h"



class MazeSearchable{

    Maze2d m_maze;
    std::vector<std::vector<int>> m_board;
     const State *m_start;  
    const State *m_end;

    public:
    MazeSearchable(Maze2d& maze){
        m_start = maze.getStart();
        m_end = maze.getEnd();
        m_board = maze.getBoard();
    }
    // MazeSearchable(Maze2d& maze): m_maze(maze){};
    const  State& getStartState() { return *m_maze.getStart();};
    const  State& getGoalState() {return *m_maze.getEnd();};
    const std::vector<std::vector<int> >& getBoard(){return m_maze.getBoard();};
    // State& getAllPossibleStates(State& state){}
    // MazeSearchable Generate(Maze2d maze);
    bool callBFS(){
        BFS* _BFS = new BFS(m_start, m_end, m_board);
        std::queue<State*> sol;
        sol = _BFS->solve();
        if (sol.front())
        {
            return true;
        }
        return false;

    }

    bool callAstar(){
        Astar* _ASTAR = new Astar(m_start,m_end,m_board);
        return true;
    }
    //     std::queue<State*> sol;
    //     sol = _ASTAR->solve();
    //     if (sol.front())
    //     {
            
    //         return true;
    //     }
    //     return false;
    // }

    MazeSearchable();
    ~MazeSearchable(){};
};

