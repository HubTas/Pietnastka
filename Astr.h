#ifndef SISE1_ASTR_H
#define SISE1_ASTR_H


#include <vector>
#include <string>
#include "Board.h"

class Astr {
private:
    int moves;
    int row;
    int column;
    char order[4];
    std::vector<Board>processed;
    int visited;
    int maxDepth;
    int wantedDepth;
    double time;
    std::string arr;

public:
    std::string getArr();

    void setArray(std::string order);

    int getMaxDepth() const;

    int getWantedDepth() const;

    double getTime() const;

    void setTime(double time);

    Astr(int row, int column);

    bool search(std::string type, Board root);

    int calculateManh(int deep, Board b);

    int calculateHamm(int deep, Board b);

    int getMoves() const;

    bool isProcessed(Board board);

    int getVisited() const;

    int getNumberOfProcessedState();

    struct compare {
        bool operator()(const Board& b1, const Board& b2) {
            if(b1.getDistance() > b2.getDistance())
                return true;
            else
                return false;
//            return b1.getDistance() > b2.getDistance();
        }
    };

};


#endif //SISE1_ASTR_H
