#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph = {
    {0, 1, 0, 0, 0, 10},
    {1, 0, 2, 1, 0, 0},
    {0, 2, 0, 0, 5, 0},
    {0, 1, 0, 0, 3, 4},
    {0, 0, 5, 3, 0, 2},
    {10, 0, 0, 4, 2, 0}
};

struct Node {
    int id;
    int g;
    int f;      // g + h
};

struct Compare{
    bool operator()(Node a, Node b){
        return a.f > b.f;   // min heap (smallest f at top)
    }
};

void a_star(int h[], int start, int goal){
    int n = graph.size();
   
    vector<bool> visited(n, false);     // visited array
    vector<int> gArr(n, INT_MAX);          // distance array
    vector<int> parent(n, -1);          // parent array

    priority_queue <Node, vector<Node>, Compare> pq;     // define pq

    gArr[start] = 0;
    pq.push({start, 0, h[start]});

    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();

        if (visited[curr.id]) continue;
        visited[curr.id] = true;
        cout << curr.id << " ";

        // goal check
        if(curr.id == goal){
            cout << "\nReached Destination" << endl;

            cout << "Path costs: ";
            for (int i = 0; i < n; i++) {
                if (gArr[i] == INT_MAX)
                    cout << "INF";
                else
                    cout << gArr[i] << " ";
            }
            cout << "\n";

            // print path
            cout << "Path: ";
            vector<int> path;
            for (int at = goal; at != 1; at = parent[at]) {
                path.push_back(at);
            }
            for(int i = path.size()-1; i >= 0; i--) {
                cout << path[i] << " -> ";
            }
            cout << "\n";
            return;
        }
       
        for (int next = 0; next < n; next++) {
            if (graph[curr.id][next] == 1) {
                int new_g = gArr[curr.id] + graph[curr.id][next];
                if (new_g < gArr[next]) {
                    gArr[next] = new_g;
                    parent[next] = curr.id;
                    pq.push({next, new_g, (new_g + h[next])});
                }
            }
        }
    }
    cout << "Not reachable" << endl;
    return;
}

int main() {
    int h[] = {5, 3, 4, 2, 6, 0};
    // int start = 0;
    // int end = 5;
    a_star(h, 0, 5);
    return 0;
}
