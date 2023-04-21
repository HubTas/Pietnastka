#include <iostream>
#include <fstream>
#include "Board.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Astr.h"

int main(int argc, char** argv) {
    std::string help = "", ciag;
    int dzr, lso, lsp, mosgr;
    double ctpo;
    int row, column;
    char order[4];

//    std::string type(argv[1]);
//    std::string additionalParametr(argv[2]);
//    std::string started(argv[3]);
//    std::string saved(argv[4]);
//    std::string data(argv[5]);


    std::string type, additionalParametr, started, saved, data;
    type = "dfs";
    additionalParametr = "DRUL";
    started = "test.txt";
    saved = "4x4_06_00008_dfs_rdul_sol.txt";
    data = "4x4_06_00008_dfs_rdul_stats.txt";


    std::ifstream readFile(started);
    if(!readFile.is_open()) {std::cout << "ERROR: File Open" << '\n';}
    getline(readFile, help, ' ');
    row = stoi(help);
    getline(readFile, help, '\n');
    column = stoi(help);
    int arr[column * row];
    for(int i = 0; i < column; i++) {
        for(int j = 0; j < row; j++) {
            if(j == row - 1)
                getline(readFile,help,'\n');
            else
                getline(readFile,help,' ');
            arr[i*4+j] = stoi(help);
        }
    }
    readFile.close();

    Board start(row, column, arr);

    if(additionalParametr != "manh" && additionalParametr != "hamm") {
        for (int i = 0; i < 4; i++) {
            order[i] = additionalParametr[i];
        }
    }
    if(type == "bfs") {
        Bfs bfs(row, column, order);
        //dodać tutaj czasy zamiast w search
        if(bfs.search(start)) {
            dzr = bfs.getWantedDepth();
            ciag = bfs.getArr();
        }
        else {
            dzr = 0;
            ciag = "";
        }
        lso = bfs.getVisited();
        lsp = bfs.getNumberOfProcessedState();
        mosgr = bfs.getMaxDepth();
        ctpo = bfs.getTime();
    }
    if(type == "dfs") {
        Dfs dfs(row, column, order);
        if(dfs.search(0,start)) {
            dzr = dfs.getWantedDepth();
            ciag = dfs.getArr();
        }
        else {
            dzr = 0;
            ciag = "";
        }
        lso = dfs.getVisited();
        lsp = dfs.getNumberOfProcessedState();
        mosgr = dfs.getMaxDepth();
        ctpo = dfs.getTime();
    }
    if(type == "astr") {
        Astr astr(row, column);
        if(astr.search(additionalParametr, start)) {
            dzr = astr.getWantedDepth();
            ciag = astr.getArr();
        }
        else {
            dzr = 0;
            ciag = "";
        }
        lso = astr.getVisited();
        lsp = astr.getNumberOfProcessedState();
        mosgr = astr.getMaxDepth();
        ctpo = astr.getTime();
    }

    std::cout << dzr << std::endl;
    std::cout << lso << std::endl;
    std::cout << lsp << std::endl;
    std::cout << mosgr << std::endl;
    std::cout << ctpo << std::endl;
    std::cout << ciag << std::endl;

//    std::ofstream writeFile1(saved);
//    writeFile1 << dzr << std::endl;
//    writeFile1 << ciag;
//    writeFile1.close();
//    std::ofstream writeFile2(data);
//    writeFile2 << dzr << std::endl;
//    writeFile2 << lso << std::endl;
//    writeFile2 << lsp << std::endl;
//    writeFile2 << mosgr << std::endl;
//    writeFile2 << ctpo;
//    writeFile2.close();

    return 0;
}
