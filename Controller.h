//Controller.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include "View.h"
#include "Model.h"
#include "Command.h"
#include "CLI.h"
#include "MazeSearchable.h"
#include <queue>


class Controller{

    View *m_view;
    Model *m_model;
    CLI* m_cli;

    public:
    Controller(View *view,Model *model, CLI* cli){
         
            m_view = view;
            m_model = model;
            m_cli = cli;

            m_cli->addCommand("Generate",new Generate(m_model,m_view));
            m_cli->addCommand("Display",new Display(m_model,m_view));
            m_cli->addCommand("Save",new Save(m_model,m_view));
            m_cli->addCommand("Load",new Load(m_model,m_view));
            m_cli->addCommand("Size",new getSize(m_model,m_view));
            m_cli->addCommand("Solve",new Solve(m_model,m_view));
            m_cli->addCommand("Solution",new showSolution(m_model,m_view));
            m_cli->addCommand("Exit",new Exit(m_model,m_view)); 
    }
        
        CLI* getCLI(){return m_cli;}
        View* getView(){return m_view;}
        Model* getModel(){return m_model;}

      void run_command(){m_view->start_view();}

      class Generate : public Command {
    private:
    Model* m_model;
    View* m_view;
public:
    Generate(Model* model,View* view):m_model(model),m_view(view){}
    ~Generate() {}
    void execute() override {
       
        std::string maze_name;
        int choice;
        std::cout << "Enter maze name:" << std::endl;
        std::cin >> maze_name;

        std::cout << "1.Generate Simple Maze" << std::endl;
        std::cout << "2.Generate Algorithmically Maze (Not Avaialavle yet)" << std::endl;
        std::cin >> choice;

        SimpleMaze2dGenerator* simple_maze = nullptr;

        switch (choice) {
            case 1:
                simple_maze = new SimpleMaze2dGenerator();
                if (simple_maze) {
                    Maze2d *maze = new Maze2d(simple_maze->Generate(maze_name));
                    m_model->addMaze(maze);
                }
                
                delete simple_maze;
                break;
        }
    }
};

class Display :public Command{
    private:
    Model* m_model;
    View* m_view;
    public:
    Display(Model* model,View* view):m_model(model),m_view(view){}
     ~Display() {};
    void execute() override {
        std::string name;
        std::cout<<"Enter maze to be displayed"<<std::endl;
        std::cin>>name;
        // m_model->getMaze(name)->print();
        Maze2d* maze = m_model->getMaze(name);
        if (maze) {
            maze->print();
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }

    }
};

class Save :public Command{
     private:
    Model* m_model;
    View* m_view;
    public:
    Save(Model* model,View* view):m_model(model),m_view(view){}
     ~Save() {}
    void execute() override {
        std::string name;
        std::cout<<"Enter maze to be saved"<<std::endl;
        std::cin>>name;
        Maze2d* maze = m_model->getMaze(name);
        if (maze) {
            std::cout<< "MAZE "<<name<<" HAS BEEN SUCCESSFULLY SAVED  !!!!"<<std::endl;
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }
        
    }
};

class Load :public Command{
     private:
    Model* m_model;
    View* m_view;
    public:
    Load(Model* model,View* view):m_model(model),m_view(view){}
     ~Load() {}
    void execute() override {
        std::string name;
        std::cout<<"enter maze name to load"<<std::endl;
        std::cin>> name;
        Maze2d* maze = m_model->getMaze(name);
        if (maze) {
            std::cout<< "MAZE "<<m_model->getMaze(name)->getName()<<" HAS BEEN SUCCESSFULLY LOAD  !!!!"<<std::endl;
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }
        
    }
};

class getSize :public Command{
     private:
    Model* m_model;
    View* m_view;
    public:
    getSize(Model* model,View* view):m_model(model),m_view(view){}
     ~getSize() {}
    void execute() override {
        std::string name;
        std::cout<<"enter maze name to get size"<<std::endl;
        std::cin>> name;
        //  maze = m_model->getMaze(name);
         Maze2d* maze = m_model->getMaze(name);
        if (maze) {
            std::vector<std::vector<int>> size = m_model->getMaze(name)->getBoard();
         int Rows = size.size();
         int Cols = size[0].size();
         std::cout<<Rows<<"x"<<Cols<<std::endl;
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }
        
        //  std::cout<<sizeof(maze)<<std::endl;
    }
};

class Solve :public Command{
     private:
    Model* m_model;
    View* m_view;
    public:
    Solve(Model* model,View* view):m_model(model),m_view(view){}
     ~Solve() {}
    void execute() override {
            int a = 0;
            std::string name;
            std::cout<<"enter maze name to be solved"<<std::endl;
            std::cin>> name;

            Maze2d* maze = m_model->getMaze(name);
        if (maze) {
            std::cout<<"1.BFS"<<std::endl;
                std::cout<<"2.A*"<<std::endl;
                std::cin>>a;

                Maze2d* maze = m_model->getMaze(name);
                if (a ==1) // BFS
                {
                    MazeSearchable* toSolve = new MazeSearchable(*maze);
                    if(toSolve->callBFS())
                    {
                        
                        m_model->getMaze(maze->getName())->setSolved(true);
                        return;
                    }
                    
                    
                }
                if (a ==2)     //A*
                {
                    MazeSearchable* toSolve = new MazeSearchable(*maze);
                    toSolve->callAstar();
                    return;
                
                }
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }

            // if(strcmp(name.c_str(),m_model->getMaze(name)->getName().c_str()) == 0)
            // {
            //     std::cout<<"1.BFS"<<std::endl;
            //     std::cout<<"2.A*"<<std::endl;
            //     std::cin>>a;

            //     Maze2d* maze = m_model->getMaze(name);
            //     if (a ==1) // BFS
            //     {
            //         MazeSearchable* toSolve = new MazeSearchable(*maze);
            //         if(toSolve->callBFS())
            //         {
                        
            //             m_model->getMaze(maze->getName())->setSolved(true);
            //             return;
            //         }
                    
                    
            //     }
            //     if (a ==2)     //A*
            //     {
            //         MazeSearchable* toSolve = new MazeSearchable(*maze);
            //         toSolve->callAstar();
            //         return;
                
            //     }
            //     }    
            }
            
};

class showSolution :public Command{
    private:
    Model* m_model;
    View* m_view;
    public:
    showSolution(Model* model,View* view):m_model(model),m_view(view){}
     ~showSolution() {}
    void execute() override {
        int a = 0;
        std::string name;

        std::cout<<"enter maze to get solution"<<std::endl;
        std::cin>> name;
         Maze2d* maze = m_model->getMaze(name);
        if (maze) {
        //  const Solution *sol = new Solution(*maze->getSolution());
        // sol->print();
        std::cout<<"Sorry maintainace function doesnt work"<<std::endl;
        } else {
            std::cout << "Maze doesn't exist." << std::endl;
        }

        
        // const Solution *solut = maze->getSolution();
        // solut->print();
        
    }
};

class Exit :public Command{
     private:
    Model* m_model;
    View* m_view;
    public:
    Exit(Model* model,View* view):m_model(model),m_view(view){}
     ~Exit() {}
    void execute() override {
        exit(0);
        // ...
    }
};

};



