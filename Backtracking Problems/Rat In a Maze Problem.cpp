#include <bits/stdc++.h>
using namespace std;

void printPath(int** solution, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << solution[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void ratInAMazeHelp(int maze[][20], int n, int** solution, int x, int y) {

    if(x == n-1 && y == n-1) {
        solution[x][y] = 1;
        printPath(solution,n);
        solution[x][y] = 0;
    }

    if(x < 0 || x > n-1 || y < 0 || y > n-1 || maze[x][y] == 0 || solution[x][y] == 1) {
        return;
    }

    solution[x][y] = 1;
    ratInAMazeHelp(maze,n,solution,x-1,y);
    ratInAMazeHelp(maze,n,solution,x+1,y);
    ratInAMazeHelp(maze,n,solution,x,y-1);
    ratInAMazeHelp(maze,n,solution,x,y+1);
    solution[x][y] = 0;

}

void ratInAMaze(int maze[][20], int n) {

    int** solution = new int*[n];
    for(int i = 0; i < n; i++) {
        solution[i] = new int[n];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }

    ratInAMazeHelp(maze,n,solution,0,0);

}

int main() {

    int maze[20][20] = { { 1, 0, 0, 0 }, 
                         { 1, 1, 0, 1 }, 
                         { 0, 1, 0, 0 }, 
                         { 1, 1, 1, 1 } };

    ratInAMaze(maze,4);

    return 0;

}
