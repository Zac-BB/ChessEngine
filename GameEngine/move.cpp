#include "move.h"
#include <unordered_map>
#include <string>
#include <iostream>

Move::Move(std::string notation){
    // notation given start file rank target file rank
    static const std::unordered_map<char,int> fileMap{
        {'a',0},
        {'b',1},
        {'c',2},
        {'d',3},
        {'e',4},
        {'f',5},
        {'g',6},
        {'h',7}
    };
    int startCol  = fileMap.at(notation.at(0)), startRow  = 8 - (notation.at(1) - '0'),
        targetCol = fileMap.at(notation.at(2)), targetRow = 8 - (notation.at(3) - '0');
    startSquare = startCol + 8 * startRow;
    targetSquare = targetCol + 8 * targetRow;
    std::cout << "string: " << notation <<std::endl;
    std::cout << "start target: "<<(int)startSquare << " , " << (int)targetSquare <<std::endl;
    std::cout << "file rank: "<<(int)startCol << " , " << (int)startRow <<std::endl;
}