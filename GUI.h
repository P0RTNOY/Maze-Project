//GUI.h
// Omer Portnoy 207251018
// Maayan Babayof 207000415

#pragma once
#include "View.h"
#include <string>
using namespace std;

class GUI :public View{
    string up;
    string down;
    string right;
    string left;

    public:
    GUI();
    ~GUI();
};