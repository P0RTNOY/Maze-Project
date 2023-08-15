//Model.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "Controller.h"
#include "Maze2d.h"
#include <unordered_map>
#include "Command.h"


class Model{
    std::unordered_map<std::string, Maze2d*> mazeTable;
    std::unordered_map<std::string, Solution*> solutionTable;
    Maze2dGenerator *maze;
    public:

    bool doCommand(Command* cmd){
        cmd->execute();}


    void addMaze(Maze2d *maze)
    {
        mazeTable[maze->getName()] = maze; 
    }

    

    


    Maze2d* getMaze(std::string mazeName) {
        if (mazeTable.find(mazeName) != mazeTable.end()) {
            return mazeTable[mazeName];
        } else {
            return nullptr;
        }
    }

    // Maze2d *getMaze(std::string mazeName)
    // {
    //     if (mazeTable[mazeName])
    //     {
    //         return mazeTable[mazeName];
    //     }
    //     else
    //         std::cout<<"maze doesnt exist"<<std::endl;
    //         return nullptr;
                
        
    // }



     const std::unordered_map<std::string, Maze2d*>& getMazeTable() const {
        return mazeTable;
    }

    // Getter for solutionTable
    const std::unordered_map<std::string, Solution*>& getSolutionTable() const {
        return solutionTable;
    }
    
    

};