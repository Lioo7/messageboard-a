#include <vector>
#include <string>
#include "Direction.hpp"
using namespace std;

namespace ariel{

class Board{
private:
uint rows;
uint columns;
vector<vector<char>> board; 

public:
Board() {
    // init 5x5 board
    board = vector<vector<char>>(5 , vector<char> (5, '_')); 
    rows = 5;
    columns = 5;
}
void post(uint row, uint column, Direction direction, string text);
string read(uint row, uint column, Direction direction, uint length);
// bool checkSize(uint row, uint column);
void boardResize(uint row, uint column);
void show();
};

}
