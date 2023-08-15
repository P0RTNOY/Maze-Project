//main.cpp
// Omer Portnoy 207251018
// Maayan Babayof 207000415
#include "Game.h"


int main()
{
   
    std::istream& inputStream = std::cin;
    std::ostream& outputStream = std::cout;
    View *view = new View();
    Model *model = new Model();
    CLI *cli = new CLI(inputStream,outputStream);
    Controller * controller = new Controller(view,model,cli);
    Game *game = new Game(controller);
    game->start();
    
    return 0;
}


