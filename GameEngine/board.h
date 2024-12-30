#pragma once

#include <cstdint>
#include <string>
#include "move.h"

class Board {
    
    uint8_t m_squares[64];

    public:
    Board();
    Board(std::string FEN_position);
    void display();
    void play(std::string fromTo);
    void play(Move move);


};

std::string fenToImage(std::string fen_position);

void fenToSquares(std::string fen_position,uint8_t* board);
std::string squaresToImage(uint8_t* board);