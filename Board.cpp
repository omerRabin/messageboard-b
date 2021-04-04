#include "Board.hpp"
#include <iostream>
/*
    Board.cpp.
    Author: Omer Rabin.
*/
using namespace std;

namespace ariel {
 void Board::post(uint row, uint col, Direction direction, string message) 
 {
     bool flag=true;// true is horizontal
        uint len=message.length();
        if(direction==Direction::Horizontal){ // update end rows and cols
            this->end_row = max(this->end_row, row);
            this->end_col = max(this->end_col, col+len);
        }
        else{
            flag=false;
            this->end_row = max(this->end_row, row+len);
            this->end_col = max(this->end_col, col);
        }
        // update start rows and cols
        this->start_col = min(this->start_col, col);
        this->start_row = min(this->start_row, row);
        if(!flag){
        for(ulong i=0 ;i<len;i++){
            this->board[row][col].c = message[i];
            row++;
        }
        }
        else
        {
            for(ulong i=0 ;i<len;i++){ // put the message
            this->board[row][col].c = message[i];
            col++;
        }
        }
    }

    string Board::read(uint row, uint col, Direction direction, uint length){
        string msgBoard;
        bool flag=true;
        if(direction == Direction:: Vertical)
        {
            flag=false;
        }
        // get the meassge according direction
        if(flag)
        {
            for(uint i=0; i<length; i++){
            msgBoard += this->board[row][col].c;
            col++;
        }
        }
        else
        {
        for(uint i=0; i<length; i++){
        msgBoard += this->board[row][col].c;
        row++;
        }
        }
        return msgBoard;
    }
    
    void Board::show() {
        // print the map
        for (uint i = this->start_row; i < this->end_row; i++) {
            for (uint j = this->start_col; j < this->end_col; j++) {
                cout << this->board[i][j].c;
            }
            cout << "\n";
        }
    }
}
