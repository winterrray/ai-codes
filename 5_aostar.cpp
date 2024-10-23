#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>
using namespace std;

vector<vector<pair<int, int>>> g = {
    {{0, -1}, {1,  3}, {0, -1}, {1, -1}, {0, -1}},
    {{1, -1}, {0, -1}, {0, -1}, {0, -1}, {0, -1}},
    {{1, -1}, {0, -1}, {0 ,-1}, {0, -1}, {1, -1}},
    {{1, -1}, {0, -1}, {0 ,-1}, {0, -1}, {1, -1}},
    {{0, -1}, {1, -1}, {0, -1}, {1, -1}, {0, -1}}
};

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void ao_star(vector<int> h, int start, int end){
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    vector<int> visited(g.size(), 0);
    vector<int> dist(g.size(), INT_MAX);

    dist[start] = 0;
    pq.push({start, h[start]});

    while(!pq.empty()){
        start = pq.top().first;
        pq.pop();
        if(visited[start] == 1) continue;
        visited[start] = true;
        cout << start << " ";

        if(start == end){
            cout << endl;
            cout << "reached!!" << endl;
            return;
        }

        for(int i = 0;i < g.size();i++){
            pair<int, int> neigh = g[start][i];
            int edge = neigh.first;
            int and_v = neigh.second;
            if(edge == 1 && visited[i] == 0){
                int cost = dist[start];
                if(and_v != -1 && visited[and_v] == 0){
                    if(cost < dist[i]){
                        dist[i] = cost;
                        // pq.push({i, h[i] + h[and_v] + cost});
                        // pq.push({and_v, h[i] + h[and_v] + cost});
                        pq.push({i, h[i] + cost});
                        pq.push({and_v, h[and_v] + cost});
                    }
                }else{
                    if(cost < dist[i]){
                        dist[i] = cost;
                        pq.push({i, h[i] + cost});
                    }
                }
            }
        }
    }
    cout << "can't reach" << endl;
}

int main(){
    vector<int> h = {3, 2, 7, 3, 0};
    int start = 0;
    int end = 4;
    ao_star(h, start, end);
}