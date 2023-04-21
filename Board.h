#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H


class Board {
private:
    int row;
    int column;
    int emptyField[2];
    int **board;
    int previousMove;
    int distance;
    int depth;
    std::string arr;

public:
    std::string getArr();
    void setArray(char value);
    int getDepth() const;
    void setDepth(int depth);
    int getDistance() const;
    void setDistance(int distance);
    Board(int row, int column, int arr[]);
    Board(const Board &b);
    std::string boardToString();
    bool checkStringBoard();
    bool compareStringBoard(Board b);
    bool moveRight();
    bool moveLeft();
    bool moveDown();
    bool moveUp();
    void setEmptyField();
    void printBoard();
    bool checkBoard();
    int getValue(int i, int j) const;
    void setValue(int i, int j, int value);
    bool equals(Board b);

    virtual ~Board();

};


#endif //UNTITLED_BOARD_H
