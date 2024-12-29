#pragma once
#include <string>
struct fen{
    std::string pieces;
    bool activeColor;
    std::string castlingRights;
    std::string enPassant;
    unsigned int halfMoveClock;
    unsigned int fullMoveClock;
};

fen stringToFen(std::string fenString);