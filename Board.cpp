#include "iostream"
#include "Board.h"


Board::Board(int boardRow, int boardColumn, int arr[]) : row(boardRow), column(boardColumn) {
    row = boardRow;
    column = boardColumn;

    board= new int *[row];
    for(int i = 0; i < row; i++) {
        board[i] = new int [column];
    }

    for(int i = 0; i < column; i++)
        for(int j = 0; j < row; j++)
            board[i][j] = arr[i * 4 + j];

    distance = 0;
    previousMove = 0;
    depth = 0;
    setEmptyField();
}

bool Board::moveRight() {
    if(emptyField[1] != column - 1 && previousMove != 2) {
        board[emptyField[0]][emptyField[1]] = board[emptyField[0]][emptyField[1] + 1];
        board[emptyField[0]][emptyField[1] + 1] = 0;
        emptyField[1]++;
        previousMove = 1;
        return true;
    }
    return false;
}

bool Board::moveLeft() {
    if(emptyField[1] != 0 && previousMove != 1) {
        board[emptyField[0]][emptyField[1]] = board[emptyField[0]][emptyField[1] - 1];
        board[emptyField[0]][emptyField[1] - 1] = 0;
        emptyField[1]--;
        previousMove = 2;
        return true;
    }
    return false;
}

bool Board::moveDown() {
    if(emptyField[0] != row - 1 && previousMove != 4) {
        board[emptyField[0]][emptyField[1]] = board[emptyField[0] + 1][emptyField[1]];
        board[emptyField[0] + 1][emptyField[1]] = 0;
        emptyField[0]++;
        previousMove = 3;
        return true;
    }
    return false;
}

bool Board::moveUp() {
    if(emptyField[0] != 0 && previousMove != 3) {
        board[emptyField[0]][emptyField[1]] = board[emptyField[0] - 1][emptyField[1]];
        board[emptyField[0] - 1][emptyField[1]] = 0;
        emptyField[0]--;
        previousMove = 4;
        return true;
    }
    return false;
}

void Board::setEmptyField() {
    for(int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++)
            if (board[i][j] == 0) {
                emptyField[0] = i;
                emptyField[1] = j;
            }
    }
}

bool Board::checkBoard() {
    int z = 1;

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if(i * j < 9) {
                if (board[i][j] != z) {
                    return false;
                }
            }
            z++;
        }
    }
    return true;
}

int Board::getValue(int i, int j) const {
    return board[i][j];
}

void Board::setValue(int i, int j, int value) {
    board[i][j] = value;
}

bool Board::equals(Board b) {
    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            if(board[i][j] != b.getValue(i, j))
                return false;
        }
    }
    return true;
}

Board::Board(Board const &b) {
    row = b.row;
    column = b.column;
    distance = b.distance;
    previousMove = b.previousMove;
    depth = b.depth;
    arr = b.arr;
    board = new int *[row];
    for(int i = 0; i < row; i++) {
        board[i] = new int [column];
    }

    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++)
            this->setValue(i,j,b.getValue(i,j));
    }
    setEmptyField();
}

int Board::getDistance() const {
    return distance;
}

void Board::setDistance(int distance) {
    Board::distance = distance;
}

Board::~Board() {
//    for(int i = 0; i < row; i++) {
//        delete [] board[i];
//    }
//    delete [] board;
}

int Board::getDepth() const {
    return depth;
}

void Board::setDepth(int depth) {
    Board::depth = depth;
}

void Board::setArray(char value) {
    arr += value;
}

std::string Board::getArr() {
    return arr;
}

