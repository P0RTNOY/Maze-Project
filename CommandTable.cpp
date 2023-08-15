// //CommandTable.cpp

// #include "CommandTable.h"
// #include "Command.h"


//  CommandTable::CommandTable()
//  {
//     commandHashtable["Generate"] = new Generate();
//     commandHashtable["Display"] = new Display();
//     commandHashtable["Save"] = new Save();
//     commandHashtable["Load"] = new Load();
//     commandHashtable["Size"] = new getSize();
//     commandHashtable["Solve"] = new Solve();
//     commandHashtable["Solution"] = new showSolution();
//     commandHashtable["Exit"] = new Exit();
//  }

//  CommandTable::~CommandTable() {
//     for (auto& pair : commandHashtable) {
//         delete pair.second;  // Delete each dynamically allocated Command object
//     }
//     commandHashtable.clear(); 
//  }