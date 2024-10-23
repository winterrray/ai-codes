#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<vector<int>> graph = {
    {0, 1, 0, 0, 0, 10},
    {1, 0, 2, 1, 0, 0},
    {0, 2, 0, 0, 5, 0},
    {0, 1, 0, 0, 3, 4},
    {0, 0, 5, 3, 0, 2},
    {10, 0, 0, 4, 2, 0}
};

struct Compare{
    bool operator()(pair<int, int> a,pair<int, int> b){
        return a.second > b.second;
    }
};

void a_star(vector<int> h, int start, int end){
    //define pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    //visited array
    vector<int> visited(graph.size(), -1);
    //dist array
    vector<int> dist(graph.size(), INT_MAX);

    dist[start] = 0;
    pq.push({start, h[start]});

    while(!pq.empty()){
        int node = pq.top().first;
        pq.pop();

        if (visited[node] == 1) continue;
        cout << node << " ";
        visited[node] = 1;

        if(node == end){
            cout << endl;
            cout << "Reached Destination" << endl;
            return;
        }
       
        for(int i = 0;i < graph[0].size();i++){
            if(visited[i] == -1 && graph[node][i] != 0){
                int cost = graph[node][i] + dist[node];
                if(cost < dist[i]){
                    pq.push({i, h[i] + cost});
                    dist[i] = cost;
                }
            }
        }
    }
    cout << "Not reachable" << endl;
    return;
}

int main() {
    vector<int> h = {5, 3, 4, 2, 6, 0};
    int start = 0;
    int end = 5;
    a_star(h, 0, 5);
    return 0;
}