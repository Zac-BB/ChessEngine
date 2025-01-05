
#pragma once
#include <string>

struct Move{
    int  startSquare;
    int targetSquare;
    public:
    Move(std::string notation);
    Move(int startSquare,int targetSquare);
};

