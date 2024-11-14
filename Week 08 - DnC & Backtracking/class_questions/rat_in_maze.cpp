#include <bits/stdc++.h>
using namespace std;

//function that will handle all the precaution cases
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>>& visited) {
    if(maze[newx][newy] == 1 && (newx >= 0 && newx < row) && (newy >= 0 && newy < col) && visited[newx][newy] == false) {
        return true;
    }
    else {
        return false;
    }
}


void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited) {
    //base case
    //destination coordinates are [row-1],[col-1]
    if (srcx == row - 1 && srcy == col-1) {
        //reached destination
        cout << output << endl;
        return;
    }

    //one case solution
    //UP
    // possibility hai 1. Path closed 2. out of bound 3. check if position is already visited
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true; //? mark visited
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited); //? call recursion
        output.pop_back();
        visited[newx][newy] = false; //? backtracking
    }
    //RIGHT
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true; //? mark visited
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited); //? call recursion
        output.pop_back();
        visited[newx][newy] = false; //? backtracking
    }
    //DOWN
    newx = srcx+1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true; //? mark visited
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited); //? call recursion
        output.pop_back();
        visited[newx][newy] = false; //? backtracking
    }
    //LEFT
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited)) {
        visited[newx][newy] = true; //? mark visited
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited); //? call recursion
        output.pop_back();
        visited[newx][newy] = false; //? backtracking
    }
}

int main() {
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;
    
    int srcx = 0;
    int srcy = 0; 
    string output = "";

    //create visited 2D array
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0) {
        //src position is Closed, that means RAT cannot move
        cout << "No Path Exists" << endl;
    }
    else {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }

    return 0;
}