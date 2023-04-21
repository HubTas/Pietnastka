#include <iostream>
#include "Dfs.h"

Dfs::Dfs(int dfsRow, int dfsColumn, const char dfsOrder[4]) : row(dfsRow), column(dfsColumn) {
    depth = 20;
    row = dfsRow;
    column = dfsColumn;
    moves = 0;
    visited = 1;
    for(int i = 0; i < 4; i++) {
        order[i] = dfsOrder[i];
    }
    maxDepth = 0;
}

bool Dfs::search(int steps, Board b) {
    if(moves == 0)
        start = clock();
    moves++;
    char letter;
    if(steps > maxDepth)
        maxDepth = steps;
    processed.push_back(b);
    if(b.checkBoard()) {
        wantedDepth = b.getDepth();
        setTime(clock()-start);
        setArray(b.getArr());
        return true;
    }
    else if(steps < depth) {
        for (int i = 0; i < 4; i++) {
            Board newNode(b);
            letter = order[i];
            if (letter == 'L') {
                if (newNode.moveLeft() && isProcessed(newNode)) {
                    newNode.setArray('L');
                    newNode.setDepth(newNode.getDepth()+1);
                    visited++;
                    if(search(steps + 1, newNode))
                        return true;
                }
            }
            if (letter == 'R') {
                if (newNode.moveRight() && isProcessed(newNode)) {
                    newNode.setArray('R');
                    newNode.setDepth(newNode.getDepth()+1);
                    visited++;
                    if(search(steps + 1, newNode))
                        return true;
                }
            }
            if (letter == 'U') {
                if (newNode.moveUp() && isProcessed(newNode)) {
                    newNode.setArray('U');
                    newNode.setDepth(newNode.getDepth()+1);
                    visited++;
                    if(search(steps + 1, newNode))
                        return true;
                }
            }
            if (letter == 'D') {
                if (newNode.moveDown() && isProcessed(newNode)) {
                    newNode.setArray('D');
                    newNode.setDepth(newNode.getDepth()+1);
                    visited++;
                    if(search(steps + 1, newNode))
                        return true;
                }
            }
        }
    }
    return false;
}

int Dfs::getMoves() const {
    return moves;
}

bool Dfs::isProcessed(Board board) {
    for(int i = 0; i < processed.size(); i++) {
        if (processed.operator[](i).equals(board))
            return false; //zamienić true z false
    }
    return true;
}

int Dfs::getNumberOfProcessedState() {
    return (int)processed.size();
}

int Dfs::getVisited() const {
    return visited;
}

int Dfs::getMaxDepth() const {
    return maxDepth;
}

int Dfs::getWantedDepth() const {
    return wantedDepth;
}

double Dfs::getTime() const {
    return time;
}

void Dfs::setTime(double time) {
    Dfs::time = time;
}

std::string Dfs::getArr() {
    return arr;
}

void Dfs::setArray(std::string order) {
    arr = order;
}
