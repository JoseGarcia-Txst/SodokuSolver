/*
 *
 * Author: Jose A Garcia -  12/19/19 Version 1.0
 *
 * Purpose: The Purpose of this program is to introuduce the topic of Dynamic Progamming.
 * This progam will compute the correct output BUT in O(n^2). This took about 5 hrs to code.
 *
 * Learned: I learned the process of backtracking and how long it takes to compute, EX: i had input
 * the "hardest Sodoku puzzle" and I got no answer. At first i stopped the code and looked for potential errors.
 * Then i ran the code using a debugger ( Insane amount of steps), until came to the realization that
 * every possible input is attempted ( Starting from 0 -> 9). I re-ran my code and after 10 seconds
 * i got the correct answer.
 *
 * Future Ideas: Find ways to optimize the program, maybe introducing Parallel programming.
 * Create a GUI so the user can understand the process of backtracking.
 *
 */

#include <iostream>
#include <vector>
#define SIZE 9

void printMatrix( std::vector<std::vector<int>> matrix);
bool zeroLocator (int &row, int &col, std::vector<std::vector<int>> matrix);
bool numInRow(int row, int num,std::vector<std::vector<int>> matrix );
bool numInCol(int col, int num, std::vector<std::vector<int>> matrix);
bool numInBox(int row, int col, int num, std::vector<std::vector<int>> matrix);
bool numAllowed(int row,int col, int num,std::vector<std::vector<int>> matrix);
bool solveBoard(std::vector<std::vector<int>> &matrix, int row, int col);


int main(){
    std::vector<std::vector<int>> board;

    // "World's hardest Sodoku puzzle
    board = {{8,0,0,0,0,0,0,0,0},
             {0,0,3,6,0,0,0,0,0},
             {0,7,0,0,9,0,2,0,0},
             {0,5,0,0,0,7,0,0,0},
             {0,0,0,0,4,5,7,0,0},
             {0,0,0,1,0,0,0,3,0},
             {0,0,1,0,0,0,0,6,8},
             {0,0,8,5,0,0,0,1,0},
             {0,9,0,0,0,0,4,0,0},};

    std::cout<<"Input Board:\n";
    printMatrix(board);
    if(solveBoard(board,0,0)) {
        std::cout<<"Solution Found!\n\nOutputBoard:\n";
        printMatrix(board);
    }
    else
        std::cout<<"Solution NOT Found!";

    return 0;
}

// BackTracking Alg that will take O(n^2), will atempt every possible combination form 0 to 9
bool solveBoard(std::vector<std::vector<int>> &matrix, int row, int col){

    if(!zeroLocator(row,col, matrix))
        return true;

    for(int num = 1 ; num <= 9; ++num){

        if(numAllowed(row,col,num,matrix)){
            matrix[row][col] = num;

            if(solveBoard(matrix,row,col))
                return true;

            matrix[row][col] = 0;
        }

    }
    return false;
}

// Returns row and col of next zero to be worked on
bool zeroLocator (int &row, int &col, std::vector<std::vector<int>> matrix){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if( matrix[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// Will check in the given row if given num is there already, True if it's already used, False Otherwise
bool numInRow(int row, int num,std::vector<std::vector<int>> matrix ){

    for (int col = 0; col < SIZE ; ++col) {
        if(matrix[row][col] == num)
            return true;
    }
    return false;
}

// Will check in the given col if given num is there already, True if it's already used, False Otherwise
bool numInCol(int col, int num, std::vector<std::vector<int>> matrix){

    for(int row = 0; row < SIZE; ++row){
        if(matrix[row][col] == num){
            return true;
        }
    }
    return false;
}

// Will check in the given box if given num is there already, True if its already used, False Otherwise
bool numInBox(int row, int col, int num, std::vector<std::vector<int>> matrix){

    // Finds out what box to start. This will calculate the position of the top left hand corner of box
    int startRow = (row  / 3) * 3;
    int startCol = (col  / 3) * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(matrix[i + startRow][j + startCol] == num)
                return true;
        }
    }
    return false;
}

// Check is the given num is legal to use in the Row, Col, and box
bool numAllowed(int row,int col, int num,std::vector<std::vector<int>> matrix){

    if(numInBox(row,col,num,matrix) || numInCol(col,num,matrix) || numInRow(row,num,matrix))
        return false;
    else
        return true;
}

void printMatrix( std::vector<std::vector<int>> matrix){

    for (int x = 0; x < SIZE; ++x) {
        for (int y = 0; y < SIZE; ++y) {
            if(y != 0 & (y) % 3 == 0)
                std::cout<<" ";
            std::cout<<matrix[x][y]<< ' ';
        }
        if(x != 0 & (x+1) %3 ==0)
            std::cout<<'\n';
        std::cout <<'\n';
    }
    std::cout <<'\n';

}
