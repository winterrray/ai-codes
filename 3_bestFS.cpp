#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1 ,0}
};

struct Node {
    int id;
    int h;
};

struct Compare{
    bool operator()(Node a, Node b){
        return a.h > b.h;   // min heap (smallest h at top)
    }
};

void best_first_search(int h[], int start, int goal){
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    priority_queue <Node, vector<Node>, Compare> pq;

    pq.push({start, h[start]});
    
    while(!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if(visited[curr.id]) continue;
        visited[curr.id] = true;
        cout << curr.id << " ";     // print the visited node

        // goal check
        if(curr.id == goal){
            cout << "\nReached destination" << endl;

            // print path
            cout << "Path: ";
            vector<int> path;
            for (int at = goal; at != -1; at = parent[at]) {
                path.push_back(at);
            }
            for (int i = path.size()-1; i>=0; i--) {
                cout << path[i] << " -> ";
            }
            cout << "\n";
            return;
        }

        for (int next = 0; next < n; next++) {
            if (graph[curr.id][next] == 1 && !visited[next]) {
                parent[next] = curr.id;
                pq.push({next, h[next]});
            }
        }
    }
    cout << "Not reachable!" << endl;
}

int main() {
    int h[] = {3, 11, 0, 9};
    int src = 0;
    int dest = 2;
    best_first_search(h, src, dest);
    return 0;
}
