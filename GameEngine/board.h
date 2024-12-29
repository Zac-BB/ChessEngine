#pragma once

#include <cstdint>
#include <string>

class Board {
    std::string m_fen;

    public:
    Board();
    Board(std::string FEN_position);
    void display();


};

std::string fenToImage(std::string fen_position);


