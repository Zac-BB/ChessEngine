#pragma once

#include <cstdint>
#include <string>
#include "move.h"
#include <vector>

class Board {
    
    uint8_t m_squares[64];
    uint8_t colorToMove;

    public:
    Board();
    Board(std::string FEN_position);
    void display();
    void play(std::string fromTo);
    void play(Move move);

    int evaluation();
    std::vector<Move> generateMoves();
    bool moveIsValid(int row,bool player1);
    bool isGameOver();


};

std::string fenToImage(std::string fen_position);

void fenToSquares(std::string fen_position,uint8_t* board);
std::string squaresToImage(uint8_t* board);