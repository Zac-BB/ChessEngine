#include "board.h"
#include "fen.h"
#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

#define START_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define NUM_ROWS 8

Board::Board() : m_fen(START_POSITION) {

}
Board::Board(std::string FEN_position) : m_fen(FEN_position) {

}
void Board::display(){
    std::cout << "Current FEN: " << m_fen << std::endl;
    std::string boardImage = fenToImage(m_fen);
    std::cout << boardImage << std::endl;

}

std::string fenToImage(std::string fen_position){
    static const std::unordered_map<char,std::string> fenToImageMap = {
        {'r', "♖"},
        {'n', "♘"},
        {'b', "♗"},
        {'q', "♕"},
        {'k', "♔"},
        {'p', "♙"},

        {'R', "♜"},
        {'N', "♞"},
        {'B', "♝"},
        {'Q', "♛"},
        {'K', "♚"},
        {'P', "♟"},

        {'1', " "},
        {'2', "  "},
        {'3', "   "},
        {'4', "    "},
        {'5', "     "},
        {'6', "      "},
        {'7', "       "},
        {'8', "        "},


    };
    // ♜♞♝♛♚♝♞♜
    // ♟♟♟♟♟♟♟♟
    // □■□■□■□■
    // ■□■□■□■□
    // □■□■□■□■
    // ■□■□■□■□
    // ♙♙♙♙♙♙♙♙
    // ♖♘♗♕♔♗♘♖
    std::string image = "";
    uint8_t row = 0,col = 0;
    for(uint8_t i = 0;i < fen_position.size();i++){     
        char character = fen_position.at(i);
        if(character == ' '){
            break;
        }

        if (isdigit(character)) {
            int n = character - '0';
            for(int i = 0;i < n;i++){
                bool rowEven = row % 2 == 0;
                bool colEven = col % 2 == 0;
                col++;
                if(rowEven^colEven){
                    image.append("□");
                }else{
                    image.append("■");
                }
            }
        }else if(character == '/'){
            image.append("\n");
            row++;
            col = 0;
        }else {
            auto str = fenToImageMap.at(character);
            image.append(str);
            col++;
        }
        
        
    }

    return image;
}