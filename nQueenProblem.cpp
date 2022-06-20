#include <iostream>

bool isSafe(int**, int, int, int);
void printAllSolutions(int**, int);
bool findQueen(int**, int, int);

int main() {
    int size = 0;
    std::cout << "Enter the size of your chess board [*]\b\b";
    std::cin >> size;
    int** board = new int*[size];
    for(int i = 0; i < size; ++i) {
        board[i] = new int[size];
        for(int j = 0; j < size; ++j) {
            board[i][j] = 0;
        }
    }    

    if(findQueen(board, 0, size)){
        printAllSolutions(board, size);
    }

    for(int h = 0; h < size; ++h) {
        delete[] board[h];
    }
    delete[] board;
    board = nullptr;
    return 0;
}

void printAllSolutions(int** board, int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << "  " << board[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(int** board, int x, int y, int n) {
    for(int row = 0; row < x; ++row) {
        if(board[row][y]){
            return false;
        }
    }

    int row = x , col = y;
    while(row >= 0 && col >= 0){
        if(board[row][col]){
            return false;
        }
        --row;
        --col;
    }

    row = x , col = y;
    while(row >= 0 && col < n) {
        if(board[row][col])
        {
            return false;
        }
        --row;
        ++col;
    }

    return true;
}

bool findQueen(int** board, int x, int n) {
    if(x >= n){
        return true;
    }

    for(int col = 0; col < n; ++col){
        if(isSafe(board, x, col, n)){
            board[x][col] = 1;
            if(findQueen(board, x + 1, n)){
                return true;
            }
            board[x][col] = 0;
        }
    }

    return false;
}