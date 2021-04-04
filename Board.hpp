#include <map>
#include <string>
#include "Direction.hpp"
/*
    Board.hpp.
    Author: Omer Rabin.
*/
using namespace std;

struct value{
    char c='_'; // under line - default character
};

namespace ariel {
    class Board {
        map<uint,map<uint,value>> board; // map represent the board
        // indexes of the board
        uint end_col;
        uint end_row;
        uint start_col;
        uint start_row; 
    public:
        Board() {
            start_col=0;
            start_row=0;
            end_col=0;
            end_row=0;
        }
        ~Board(){}; // destructor
        void post(uint row, uint col, Direction direction, std::string message);
        std::string read(uint row, uint col, Direction direction, uint length);
        void show();
    };

}
