#include "board.h"
// #include "fen.h"
#include "piece.h"

#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

#define START_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define NUM_ROWS 8

Board::Board(){
    fenToSquares(START_POSITION,m_squares);
}

Board::Board(std::string FEN_position){
    fenToSquares(FEN_position,m_squares);
}
void Board::display(){
    // std::cout << "Current FEN: " << m_fen << std::endl;
    
    std::string boardImage = squaresToImage(m_squares);
    std::cout << boardImage << std::endl;   std::string image = "";

}

void Board::play(std::string fromTo){
    // std::cout << "string" <<std::endl;
    play(Move(fromTo));
}
void Board::play(Move move){
    // std::cout << "actual play move" <<std::endl;
    // std::cout << move.startSquare << " , " << move.targetSquare <<std::endl;
    m_squares[move.targetSquare] = m_squares[move.startSquare];
    m_squares[move.startSquare] = Piece::None;
    // std::cout << "made it to the end" <<std::endl;
}





int gridToIndex(int row, int col){
    return 8 * row + col;
}
void fenToSquares(std::string fen_position,uint8_t* board){

    static const std::unordered_map<char,uint8_t> fenToBoard = {
        {'r', Piece::Rook},
        {'n', Piece::Knight},
        {'b', Piece::Bishop},
        {'q', Piece::Queen},
        {'k', Piece::King},
        {'p', Piece::Pawn}
    };
    uint8_t row = 0,col = 0;
    for(uint8_t i = 0;i < fen_position.size();i++){     
        char character = fen_position.at(i);
        if(character == ' '){
            break;
        }

        if (isdigit(character)) {
            int n = character - '0';
            for(int i = 0;i < n;i++){
                board[gridToIndex(row,col)] = Piece::None;
                col++;
            }
        }else if(character == '/'){
            row++;
            col = 0;
        }else {
            uint8_t color = isupper(character) ? Piece::White : Piece::Black;
            board[gridToIndex(row,col)] = color | fenToBoard.at(tolower(character));
            col++;
        }
        // std::cout << character << "--" << (int)board[gridToIndex(row,col)] <<std::endl;
        // printf("%c -- %x\n",character,board[gridToIndex(row,col)]);
        // std::cout << (int)row << " , " << (int)col <<std::endl;
    }
    // for(int i = 0; i < 64; i++){
    //     printf("%x\n",board[i]);
    // }
}


std::string squaresToImage(uint8_t* board){
    const static std::unordered_map<uint8_t,std::string> whiteMap{
        {Piece::King,"♚"},
        {Piece::Queen,"♛"},
        {Piece::Rook,"♜"},
        {Piece::Bishop,"♝"},
        {Piece::Knight,"♞"},
        {Piece::Pawn,"♟"},
    };
    const static std::unordered_map<uint8_t,std::string> blackMap{
        {Piece::King,"♔"},
        {Piece::Queen,"♕"},
        {Piece::Rook,"♖"},
        {Piece::Bishop,"♗"},
        {Piece::Knight,"♘"},
        {Piece::Pawn,"♙"}

    };
    //hashmap chosen over array since it has a smaller memory footprint
    std::string image;
    uint8_t pieceMask = 0x0f;
    uint8_t colorMask = 0x10;
    for(int i = 0; i < 64 ;i++){
        uint8_t piece = board[i] & pieceMask;
        uint8_t color = board[i] & colorMask;
        // std::cout << "image: " << image << std::endl;
        if(i % 8 == 0){
            image.append("\n");
        }
        if(piece == Piece::None){
            int row = i/8;
            int col = i%8;
            if((row + col) % 2 == 0){
                image.append("■");
            }else{
                image.append("□");
            }
        }else if(color == Piece::White){
            image.append(whiteMap.at(piece));
        }else{
            image.append(blackMap.at(piece));
        }
        
        // std::cout << "end of the loop" << std::endl;
    }
    return image;
}

