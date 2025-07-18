#include <iostream>
using namespace std;

bool corner_checker (int i, int j, int rows, int cols) {
    // a function to return true if a cell is in a corner (special case) and 0 if not
    if ( (i ==0 && j == 0) || (i == rows-1 && j == cols-1)|| (i == 0 && j == cols-1) || (i = rows-1 && j == 0)) {
        return true;
    } else {
        return false;
    }
}
bool edge_checker (int i, int j, int rows, int cols) {
    // a function to return true if a cell is on an edge (special) and 0 if not
    if ( (i == 0) || (i == rows-1) || (j == 0) || (j == cols-1) ) {
        return true;
    } else {
        return false;
    } 
}

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
    // very important - the updates happen simulatneously, not cell-wise

    // Any live cell with fewer than two live neighbors dies (underpopulation).
    // Any live cell with two or three live neighbors lives on.
    // Any live cell with more than three live neighbors dies (overpopulation).
    // Any dead cell with exactly three live neighbors becomes alive (reproduction)

    // a cell in a value in the 2D array, a neighbor is an adjacent cell - including diagonals
    // the cells have at least 2 and at most 8 neighbors 
    // 4 : 3 - the corners
    // (rows - 2) + (cols - 2) : 5 - the sides other than the corners
    // rows * cols - corners - sides : 8 - center/enclosed cells 

    // for a single step
    // next board to populate as we roll over the current one
    int next_board[rows][cols];    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Corner checks
            bool corner = false;
            if (i == 0 && j == 0) {
                int living_neighbors = board[0][1] + board[1][0] + board[1][1];
                // I can build a neighbor sum live/death function. 
                return corner = true;
            } else if (i == 0 & j == cols-1) {
                int living_neighbors = board[0][cols-2] + board[1][cols-1] + board[1][cols-2];
                return corner = true;
            } else if ( i == rows-1 && j == 0) {
                int living_neighbors = board[rows-2][0] + board[rows-2][1] + board[rows-1][1];
                return corner = true;
            } else if ( i == rows-1 && j == cols-1) {
                int living_neighbors = board[rows-2][cols-1]+board[rows-2][cols-2] + board[rows-1][cols-2];
                return corner = true;
            } 

            // start edge checks
            bool edge = false;
            if (not corner){
                
            }


            }

        }


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