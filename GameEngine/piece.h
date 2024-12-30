#pragma once
#include <cstdint>


class Piece {
    /*
    information of the Piece is a single byte the lower 4 bits hold piece type
    */
    uint8_t m_pieceInfo = 0x00;
    
    public:
    
    static const uint8_t None;
    static const uint8_t King;
    static const uint8_t Queen;
    static const uint8_t Rook;
    static const uint8_t Bishop;
    static const uint8_t Knight;
    static const uint8_t Pawn ;

    static const uint8_t White;
    static const uint8_t Black;

    Piece(){

    }
    Piece(uint8_t cast) 
    : m_pieceInfo(cast){
        
    }
    operator uint8_t(){
        return m_pieceInfo;
    }
};