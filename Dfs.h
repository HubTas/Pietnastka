#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H


#include "Board.h"
#include <vector>

class Dfs {
private:
    int moves;
    int row;
    int column;
    char order[4];
    int depth;
    std::vector<Board>processed; //unorder set/ unorder map
    int visited;
    int maxDepth;
    int wantedDepth;
    double time;
    clock_t start;
    std::string arr;

public:
    std::string getArr();

    void setArray(std::string order);

    Dfs(int row, int column, const char dfsOrder[4]);

    bool search(int steps, Board b);

    double getTime() const;

    void setTime(double time);

    int getWantedDepth() const;

    int getMoves() const;

    int getVisited() const;

    int getMaxDepth() const;

    bool isProcessed(Board board);

    int getNumberOfProcessedState();
};


#endif //UNTITLED_DFS_H
