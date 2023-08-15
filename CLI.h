//CLI.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#pragma once
#include <iostream>
#include "CommandTable.h"
#include "Command.h"
#include <map>
#include <string>
#include <iostream>
#include <unordered_map>




class CLI{
private:
    std::istream& In; // Use std::istream reference
    std::ostream& Out; // Use std::ostream reference
    std::unordered_map<std::string, Command*> commandTable;

public:
    
    CLI(std::istream& in, std::ostream& out); // Constructor declaration
    ~CLI();
    void addCommand(std::string name,Command* cmd);
    
     const std::unordered_map<std::string, Command*>& getCommandTable() const {
        return commandTable;
    }
    void start();
};


