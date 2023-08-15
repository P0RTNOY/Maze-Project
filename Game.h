//Game.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "Maze2d.h"
#include <vector>
#include "Controller.h"




class Game {

    Controller *m_controller;


    public:

    Game(Controller* controller)
    {
        m_controller = controller;
    }
            
        
        // void start(){m_controller->run_command();} 

        void start(){
            m_controller->getCLI()->start();
        }
    };
    


   

