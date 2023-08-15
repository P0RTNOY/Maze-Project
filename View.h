//View.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "CLI.h"
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Controller.h"


class View{
    CLI* m_cmd;
    

    public:
    View(){};
    
    void start_view(){m_cmd->start();}
    void print(Maze2d maze){
        maze.print();
    }

};

