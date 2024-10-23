#include <iostream>
#include <vector>
using namespace std;

void BFS(int start, vector <vector <int>> &edges, vector <bool> &visited, int n) {
    int q[20];
    int front=0, rear=0;

    q[rear++]=start;
    
    visited[start] = true;

    while (front < rear) {
        int node = q[front++];

        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (edges[node][i] == 1 && !visited[i]) {
                q[rear++] = i;

                visited[i] = true;
            }
        }
    }    
}

void DFS (int node, vector <vector <int>> &edges, vector<bool> &visited, int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[node][i]==1) {
            DFS(i, edges, visited, n);
        }
    }    
}

int main() {
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

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
    BFS(startNode, edges, visited, n);

    cout << "DFS starting from node " << startNode << ": ";
    DFS(startNode, edges, visited, n);

    return 0;
}