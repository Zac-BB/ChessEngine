#include <iostream>

#include "GameEngine/board.h"
#include "GameEngine/fen.h"

int main(){
    std::cout << "Hello World!" << std::endl;
    Board gameState = Board(/*"4k2r/6r1/8/8/8/8/3R4/R3K3 w Qk - 0 1"*/);
    
    // fen gamePose = stringToFen("4k2r/6r1/8/8/8/8/3R4/R3K3 w Qk - 0 1");
    while(true){
        std::string userString;
        gameState.display();
        std::cout << "enter the player move" << std::endl;
        std::cin >> userString;
        std::cout << userString << std::endl;
        if(userString == "q"){
            break;
        }else{
            gameState.play(userString);
        }
    }
    return 0;
}