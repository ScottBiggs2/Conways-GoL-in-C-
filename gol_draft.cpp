#include <iostream>
using namespace std;

// Any live cell with fewer than two live neighbors dies (underpopulation).
// Any live cell with two or three live neighbors lives on.
// Any live cell with more than three live neighbors dies (overpopulation).
// Any dead cell with exactly three live neighbors becomes alive (reproduction)
 int cell_status (int i, int j, int rows, int cols, int living_neighbors) {
    int alive = 0;
    if (living_neighbors < 2 || living_neighbors > 3) {
        alive = 0;
    } else if (living_neighbors == 3 || living_neighbors == 2) {
        alive = 1;
    } else {
        alive = 0;
    }
    return alive;
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


    cout << "Starting board... \n";
    // cout << "Simulating " << rows << " by " << cols << " board for " << steps << " steps...";

    // Make rows, cols matrix of ints
    int board[rows][cols];

    // populates the board w/ 1s for even row+col and 0's for odd
    // for (int i = 0; i<rows; i++) {
    //     for (int j = 0; j < cols; j++) {
            
    //         if ( (i+j)%2 == 0) {
    //             board[i][j] = 1;
    //         } else {
    //             board[i][j] = 0;
    //         }
    //     }
    // }

    // A little walking guy
    // 0 1 0
    // 0 0 1
    // 1 1 1
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            board[i][j] = 0;
            if (i == 0 && j == 1) {
                board[i][j] = 1;
            }
            if (i == 1 && j == 2) {
                board[i][j] = 1;
            }
            if (i == 2 && (j == 0 || j == 1 || j == 2 )) {
                board[i][j] = 1;
            }

        }
    }

    for (int i = 0; i <rows; i++) {
        // inner loop (elements within rows)
        for (int j = 0; j<cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
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

    for (int t = 0; t < steps; t++) {
        int next_board[rows][cols];    
        for (int i = 0; i<rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Corner checks
                bool corner = false;
                if (i == 0 && j == 0) {
                    int living_neighbors = board[0][1] + board[1][0] + board[1][1];
                    next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                    corner = true;

                } else if (i == 0 && j == cols-1) {
                    int living_neighbors = board[0][cols-2] + board[1][cols-1] + board[1][cols-2];
                    next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                    corner = true;

                } else if ( i == rows-1 && j == 0) {
                    int living_neighbors = board[rows-2][0] + board[rows-2][1] + board[rows-1][1];
                    next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                    corner = true;

                } else if ( i == rows-1 && j == cols-1) {
                    int living_neighbors = board[rows-2][cols-1]+board[rows-2][cols-2] + board[rows-1][cols-2];
                    next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                    corner = true;
                } 

                // start edge checks
                bool edge = false;
                bool center = false;
                if (not corner){
                    if (i == 0) { // top row
                        int living_neighbors = board[0][j-1] + board[0][j+1] + board[1][j-1] + board[1][j] + board[1][j+1];
                        next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                        edge = true;
                    } else if (i == rows-1) { // bottom row
                        int living_neighbors = board[rows-1][j-1] + board[rows-1][j+1] + board[rows-2][j-1] + board[rows-2][j] + board[rows-2][j+1];
                        next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                        edge = true;
                    } else if (j == 0) { // left col
                        int living_neighbors =  board[i-1][j] + board[i+1][j] + board[i][j+1] + board[i-1][j+1] + board[i+1][j+1];
                        next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                        edge = true;
                    } else if (j == cols-1) { // right col
                        int living_neighbors = board[i-1][j] + board[i+1][j] + board[i][j-1] + board[i-1][j-1] +  board[i+1][j-1];
                        next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                        edge = true;
                    } else {
                        edge = false;
                        center = true;
                    }
                } 

                if (not corner && not edge) {
                    int living_neighbors = board[i][j-1] + board[i][j+1] + board[i-1][j-1] + board[i-1][j] + board[i-1][j+1] + board[i+1][j-1] + board[i+1][j] + board[i+1][j+1];
                    next_board[i][j] = cell_status(i, j, rows, cols, living_neighbors);
                    center = true;
                } 
            }
        }


        // print the board state
        cout << "Step " << t+1 << endl;
        for (int i = 0; i <rows; i++) {
            // inner loop (elements within rows)
            for (int j = 0; j<cols; j++) {
                cout << next_board[i][j] << " ";
            }
            cout << endl;
        }

        // reset board to next board before looping
        for (int i = 0; i <rows; i++) {
            // inner loop (elements within rows)
            for (int j = 0; j<cols; j++) {
                board[i][j] = next_board[i][j];
            }
        }
    
    }

}