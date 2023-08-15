//Command.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <string>
#include "CommandTable.h" // Include CommandTable class definition
#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"




class Command {
public:
    // Command(const Command& other)
    // {

    // }
    virtual ~Command(){}
    virtual void execute() = 0;
   

};


// class Generate : public Command {
//     private:
//     Model* m_model;
//     View* m_view;
// public:
//     Generate(Model* model,View* view):m_model(model),m_view(view){}
//     ~Generate() {}
//     void execute() override {
       
//         std::string maze_name;
//         int choice;
//         std::cout << "Enter maze name:" << std::endl;
//         std::cin >> maze_name;

//         std::cout << "1.Generate Simple Maze" << std::endl;
//         std::cout << "2.Generate Algorithmically Maze" << std::endl;
//         std::cin >> choice;

//         SimpleMaze2dGenerator* simple_maze = nullptr;

//         switch (choice) {
//             case 1:
//                 simple_maze = new SimpleMaze2dGenerator();
//                 if (simple_maze) {
//                     Maze2d *maze = new Maze2d(simple_maze->Generate(maze_name));
//                     m_model->addMaze(maze);
//                     m_view->print(*m_model->getMaze(maze->getName()));
//                 }
                
//                 delete simple_maze;
//                 break;
//         }
//     }
// };








// class Display :public Command{
//     public:
//      ~Display() {}
//     void execute() override {
//         // ...
//     }
// };

// class Save :public Command{
//     public:
//      ~Save() {}
//     void execute() override {
//         // ...
//     }
// };

// class Load :public Command{
//     public:
//      ~Load() {}
//     void execute() override {
//         // ...
//     }
// };

// class getSize :public Command{
//     public:
//      ~getSize() {}
//     void execute() override {
//         // ...
//     }
// };

// class Solve :public Command{
//     public:
//      ~Solve() {}
//     void execute() override {
//         // ...
//     }
// };

// class showSolution :public Command{
//     public:
//      ~showSolution() {}
//     void execute() override {
//         // ...
//     }
// };

// class Exit :public Command{
//     public:
//      ~Exit() {}
//     void execute() override {
//         // ...
//     }
// };





