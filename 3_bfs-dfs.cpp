#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector <vector <int>> &edges, vector <bool> &visited1, int n) {
    // int q[20], front=0, rear=0;
    queue<int> q;

    // q[rear++]=start;
    q.push(start);
    
    visited1[start] = true;

    // while (front < rear) {
    while (!q.empty()) {
    
        // int node = q[front++];
        int node = q.front();
        q.pop();

        cout << node << " ";

        if(goal == node) break;

        for (int i = node; i < edges.size(); i++) {
            if (edges[node][i] == 1 && !visited1[i]) {
                // q[rear++] = i;
                q.push(i);
                visited1[i] = true;
            }
        }
    }    
}


void DFS (int node, vector <vector <int>> &edges, vector<bool> &visited2, int n) {
    visited2[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[node][i]==1) {
            DFS(i, edges, visited2, n);
        }
    }    
}

int main() {
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited1(n, false);
    vector<bool> visited2(n, false);

    cout << "Enter the edges :" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "BFS starting from node " << startNode << ": ";
    BFS(startNode, edges, visited1, n);

    cout << "DFS starting from node " << startNode << ": ";
    DFS(startNode, edges, visited2, n);

    return 0;
}
