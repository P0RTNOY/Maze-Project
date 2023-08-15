// //CommandTable.h
// #pragma once
// #include <unordered_map>
// #include <string>

// class Command;

// class CommandTable {
// private:
//     std::unordered_map<std::string,Command*> commandHashtable;

// public:
//     CommandTable();
//     ~CommandTable();

//       Command* getCommand(const std::string& commandName) {
//         auto it = commandHashtable.find(commandName);
//         if (it != commandHashtable.end()) {
//             return it->second;
//         }
//         return nullptr;
//     }

//     const std::unordered_map<std::string, Command*>& getCommandHashtable() const {
//         return commandHashtable;
//     }
// };



