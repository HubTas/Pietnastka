#include <iostream>
#include <queue>
#include "Astr.h"
#include "math.h"

Astr::Astr(int astrRow, int astrColumn) : row(astrRow), column(astrColumn) {
    row = astrRow;
    column = astrColumn;
    moves = 0;
    visited = 0;
    maxDepth = 0;
    order[0] = 'R';
    order[1] = 'L';
    order[2] = 'D';
    order[3] = 'U';
}

bool Astr::search(std::string type, Board root) {
    char letter;
    clock_t start = clock();
    std::priority_queue<Board, std::vector<Board>, compare>que;
    if(type == "hamm") {
        root.setDistance(calculateHamm(1,root));
    }
    if(type == "manh") {
        root.setDistance(calculateManh(1,root));
    }
    que.push(root);
    visited++;
    while(que.size() != 0) {
        Board node = que.top();
        que.pop();
        if (node.getDepth() > maxDepth)
            maxDepth = node.getDepth();
        if (node.checkBoard()) {
            wantedDepth = node.getDepth();
            maxDepth = wantedDepth + 1;
            setTime(clock() - start);
            setArray(node.getArr());
            return true;
        }
        for (int i = 0; i < 4; i++) {
            Board newNode(node);
            letter = order[i];
            processed.push_back(newNode);
            if (letter == 'L') {
                if (newNode.moveLeft() && isProcessed(newNode)) {
                    newNode.setArray('L');
                    newNode.setDepth(newNode.getDepth() + 1);
                    if (type == "hamm")
                        newNode.setDistance(calculateHamm(newNode.getDepth(), newNode));
                    if (type == "manh")
                        newNode.setDistance(calculateManh(newNode.getDepth(), newNode));
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'R') {
                if (newNode.moveRight() && isProcessed(newNode)) {
                    newNode.setArray('R');
                    newNode.setDepth(newNode.getDepth() + 1);
                    if (type == "hamm")
                        newNode.setDistance(calculateHamm(newNode.getDepth(), newNode));
                    if (type == "manh")
                        newNode.setDistance(calculateManh(newNode.getDepth(), newNode));
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'U') {
                if (newNode.moveUp() && isProcessed(newNode)) {
                    newNode.setArray('U');
                    newNode.setDepth(newNode.getDepth() + 1);
                    if (type == "hamm")
                        newNode.setDistance(calculateHamm(newNode.getDepth(), newNode));
                    if (type == "manh")
                        newNode.setDistance(calculateManh(newNode.getDepth(), newNode));
                    que.push(newNode);
                    visited++;
                }
            }
            if (letter == 'D') {
                if (newNode.moveDown() && isProcessed(newNode)) {
                    newNode.setArray('D');
                    newNode.setDepth(newNode.getDepth() + 1);
                    if (type == "hamm")
                        newNode.setDistance(calculateHamm(newNode.getDepth(), newNode));
                    if (type == "manh")
                        newNode.setDistance(calculateManh(newNode.getDepth(), newNode));
                    que.push(newNode);
                    visited++;
                }
            }
        }
    }
    setTime(clock() - start);
    return false;
}

int Astr::getMoves() const {
    return moves;
}

bool Astr::isProcessed(Board board) {
    for(int i = 0; i < processed.size(); i++) {
        if (processed.operator[](i).equals(board))
            return false;
    }
    return true;
}

int Astr::calculateManh(int deep, Board b) {
    int z = 1;
    int correctBoard[16][2] = {0,0,0,1,0,2,0,3,
                               1,0,1,1,1,2,1,3,
                               2,0,2,1,2,2,2,3,
                               3,0,3,1,3,2,3,3};
    for(int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if(b.getValue(i,j) != z && b.getValue(i,j) != 0) {
                int x_dif = abs(correctBoard[b.getValue(i,j)][0] - i);
                int y_dif = abs(correctBoard[b.getValue(i,j)][1] - j);
                deep += x_dif + y_dif;
            }
            z++;
        }
    }
    return deep;
}


int Astr::calculateHamm(int deep, Board b) {
    int z = 1;
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if (b.getValue(i,j) != z && b.getValue(i,j) != 0) {
                deep++;
            }
            z++;
        }
    }
    return deep;
}

int Astr::getNumberOfProcessedState() {
    return (int)processed.size();
}

int Astr::getVisited() const {
    return visited;
}

int Astr::getMaxDepth() const {
    return maxDepth;
}

int Astr::getWantedDepth() const {
    return wantedDepth;
}

double Astr::getTime() const {
    return time;
}

void Astr::setTime(double time) {
    Astr::time = time;
}

std::string Astr::getArr() {
    return arr;
}

void Astr::setArray(std::string order) {
    arr = order;
}
