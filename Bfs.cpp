#include <iostream>
#include "Bfs.h"
#include "queue"

Bfs::Bfs(int bfsRow, int bfsColumn, const char bfsOrder[4]) : row(bfsRow), column(bfsColumn) {
    row = bfsRow;
    column = bfsColumn;
    moves = 0;
    visited = 0;
    maxDepth = 0;
    for(int i = 0; i < 4; i++) {
        order[i] = bfsOrder[i];
    }
}

int Bfs::getMoves() const {
    return moves;
}

bool Bfs::search(Board root) {
    clock_t start = clock();
    char letter;
    std::queue<Board>que;
    que.push(root);
    visited++;
    while(que.size() != 0) {
        Board node = que.front();
        que.pop();
        if(node.getDepth() > maxDepth)
            maxDepth = node.getDepth();
        processed.push_back(node);
        if(node.checkBoard()) {
            wantedDepth = node.getDepth();
            maxDepth = wantedDepth + 1;
            setTime(clock()-start);
            setArray(node.getArr());
            return true;
        }
        for(int i = 0; i < 4; i++) {
            Board newNode(node);
            letter = order[i];
            if (letter == 'L') {
                if (newNode.moveLeft() && isProcessed(newNode)) {
                    newNode.setArray('L');
                    newNode.setDepth(newNode.getDepth()+1);
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'R') {
                if (newNode.moveRight() && isProcessed(newNode)) {
                    newNode.setArray('R');
                    newNode.setDepth(newNode.getDepth()+1);
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'U') {
                if (newNode.moveUp() && isProcessed(newNode)) {
                    newNode.setArray('U');
                    newNode.setDepth(newNode.getDepth()+1);
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'D') {
                if (newNode.moveDown() && isProcessed(newNode)) {
                    newNode.setArray('D');
                    newNode.setDepth(newNode.getDepth()+1);
                    que.push(newNode);
                    visited++;
                }
            }
        }
    }
    setTime(clock()-start);
    return false;
}

bool Bfs::isProcessed(Board board) {
    for(int i = 0; i < processed.size(); i++) {
        if (processed.operator[](i).equals(board))
            return false;
    }
    return true;
}

int Bfs::getNumberOfProcessedState() {
    return (int)processed.size();
}

int Bfs::getVisited() const {
    return visited;
}

int Bfs::getMaxDepth() const {
    return maxDepth;
}

int Bfs::getWantedDepth() const {
    return wantedDepth;
}

double Bfs::getTime() const {
    return time;
}

void Bfs::setTime(double time) {
    Bfs::time = time;
}

void Bfs::setArray(std::string order) {
    arr = order;
}

std::string Bfs::getArr() {
    return arr;
}

