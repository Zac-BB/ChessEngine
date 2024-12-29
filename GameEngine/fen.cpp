#include <string>
#include <iostream>


struct fen{
    std::string pieces;
    bool activeColor;
    std::string castlingRights;
    std::string enPassant;//false = white,true = black
    unsigned int halfMoveClock;
    unsigned int fullMoveClock;
};

fen stringToFen(std::string fenString){
    fen constructedFEN = fen();
    unsigned int start = 0,end = fenString.find(" ",0);
    constructedFEN.pieces = fenString.substr(start,end);
    std::cout << constructedFEN.pieces << std::endl;
    constructedFEN.activeColor = fenString.at(end+1) == 'b';
    std::cout << constructedFEN.activeColor << std::endl;
    start = end+1;
    end = fenString.find(" ",0);
    return constructedFEN;
}