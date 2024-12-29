#include <iostream>

#include "GameEngine/board.h"
#include "GameEngine/fen.h"

int main(){
    std::cout << "Hello World!" << std::endl;
    Board gameState = Board("4k2r/6r1/8/8/8/8/3R4/R3K3 w Qk - 0 1");
    gameState.display();
    fen gamePose = stringToFen("4k2r/6r1/8/8/8/8/3R4/R3K3 w Qk - 0 1");
    return 0;
}