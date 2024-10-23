#include <iostream>
using namespace std;
#define n 4

bool isSafe (bool graph[n][n], int color[n], int curr, int col) {
    for (int i = 0; i < n; i++)
        if (graph[curr][i] && col == color[i])  return false;
    return true;    
}

bool graphColor (bool graph[n][n], int color[n], int curr, int m) {
    if (curr == n) return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(graph, color, curr, col)) {
            color[curr] = col;
            if (graphColor(graph, color, curr+1, m)) return true;
            color[curr] = 0;
        }
    }
    return false;    
}

int main() {
    int m;
    cout << "enter chromatic number : ";
    cin >> m;

    bool graph[n][n];
    cout << "enter graph matrix : ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }        
    }
    // bool graph[n][n] = {
    //     {0,1,1,1},
    //     {1,0,1,0},
    //     {1,1,0,1},
    //     {1,0,1,0}
    // };

    // m=3;

    int color[n]={0};

    if (graphColor(graph, color, 0, m) == false) {
        cout << "No solution";
        return 0;
    }
    
    cout << "Assigned colors : " << endl;
    for (int i=0; i<n; i++) {
        cout << i << " -> " << color[i] << endl;
    }
    return 0;
}