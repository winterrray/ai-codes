#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<vector<int>> g = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1 ,0}
};

struct comparator{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void best_first_search(vector<int> h, int src, int dest){
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

    vector<int> visited(g.size(), false);
    vector<int> dist(g.size(), INT_MAX);

    pq.push({src, h[src]});
    dist[src] = 0;
    
    while(!pq.empty()){
        src = pq.top().first;
        pq.pop();

        if(visited[src]) continue;
        visited[src] = true;
        cout << src << " ";
        if(src == dest){

            cout << "dest reached" << endl;
            return;
        }

        for(int i = 0;i < g.size();i++){
            if(!visited[i] && g[src][i] != 0){
                int cost = dist[src];
                if(cost < dist[i]){
                    dist[i] = cost;
                    pq.push({i, cost + h[i]});
                }
            }
        }
    }
    cout << "can't be reached!" << endl;
}

int main() {
    // code
    vector<int> h = {3, 11, 0, 9};
    int src = 0;
    int dest = 2;
    best_first_search(h, src, dest);
    return 0;
}