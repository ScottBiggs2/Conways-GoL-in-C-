#include <iostream>
using namespace std;

int main () {
    
    // Prompt for board size rows, cols and number of simulation steps
    int rows, cols, steps;
    cout << "Board height (rows): ";
    cin >> rows;
    cout << "Board width (cols): ";
    cin >> cols;
    cout << "For how many steps? ";
    cin >> steps;

    // cout << "Simulating " << rows << " by " << cols << " board for " << steps << " steps...";

    // Make rows, cols matrix of ints
    int board[rows][cols];

    // populates the board w/ 1s for even row+col and 0's for odd
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if ( (i+j)%2 == 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    // do step-wise logic w/ conway GoL rules (0: dead, 1: alive): 

    // Any live cell with fewer than two live neighbors dies (underpopulation).
    // Any live cell with two or three live neighbors lives on.
    // Any live cell with more than three live neighbors dies (overpopulation).
    // Any dead cell with exactly three live neighbors becomes alive (reproduction)

    // print the board state
    for (int i = 0; i <rows; i++) {
        // inner loop (elements within rows)
        for (int j = 0; j<cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}