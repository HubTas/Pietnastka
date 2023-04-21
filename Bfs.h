#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H

#include <string>
#include <vector>
#include "Board.h"

class Bfs {
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

    Bfs(int row, int column, const char bfsOrder[4]);

    bool search(Board root);

    double getTime() const;

    void setTime(double time);

    int getMoves() const;

    int getWantedDepth() const;

    int getMaxDepth() const;

    int getVisited() const;

    bool isProcessed(Board board);

    int getNumberOfProcessedState();
};


#endif //UNTITLED_BFS_H
