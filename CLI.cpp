//CLI.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "CLI.h"

CLI::CLI(std::istream& in, std::ostream& out)
    : In(in), Out(out) {
            

    // commandTable["Generate"] = new Generate();
    // commandTable["Display"] = new Display();
    // commandTable["Save"] = new Save();
    // commandTable["Load"] = new Load();
    // commandTable["Size"] = new getSize();
    // commandTable["Solve"] = new Solve();
    // commandTable["Solution"] = new showSolution();
    // commandTable["Exit"] = new Exit();
}

CLI::~CLI() {
    // Destructor implementation
}

void CLI::addCommand(std::string name,Command* cmd)
{
    commandTable[name] = cmd;
}

void CLI::start() {
    while (true) {
        std::string cmd;
         int count;
        std::cout << "Type Option:" << std::endl;
        // std::cout<< commandTable["Generate"]
        // Display available commands
        for (auto pair = commandTable.begin(); pair != commandTable.end(); ++pair) {
           
            // count++;
            // std::cout<<count<<std::endl;
            std::cout << pair->first << std::endl;
        }
        
        std::cin >> cmd;
        
        if (commandTable.find(cmd) != commandTable.end()) {
            commandTable.at(cmd)->execute();
        } else {
            std::cout << "Invalid option!" << std::endl;
        }
    }
}




