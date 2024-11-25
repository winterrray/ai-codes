#include <iostream>
#include <climits>
#include <vector>
using namespace std;

#define MAX_NODES 50

// Node structure to store node properties
struct Node {
    int id;                 // Unique identifier for the node
    int heuristic;          // Heuristic value of the node
    bool visited;           // Flag to check if the node is visited
    int optimal;            // Index of the optimal child
    int num_children;       // Number of children the node has
    vector<int> children;   // List of child node IDs
    vector<int> type;       // List of connection types (AND/OR)
    vector<int> cost;       // List of costs to each child node
};

// Global graph (array of nodes)
Node graph[MAX_NODES];
int num_nodes, num_connections;

void inputGraph() {
    cout << "Enter the number of nodes: ";
    cin >> num_nodes;

    cout << "Enter node id and heuristics of each node:\n";
    for (int i = 0; i < num_nodes; i++) {
        // graph[i].id = i;
        graph[i].visited = false;
        graph[i].optimal = -1;
        graph[i].num_children = 0;
        cin >> graph[i].id >> graph[i].heuristic;
    }

    cout << "Enter the number of connections: ";
    cin >> num_connections;

    cout << "Enter parent_id child_id cost AND/OR (1 for AND, 0 for OR):\n";
    for (int i = 0; i < num_connections; i++) {
        int parent, child, cost, type;
        cin >> parent >> child >> cost >> type;

        graph[parent].children.push_back(child);
        graph[parent].cost.push_back(cost);
        graph[parent].type.push_back(type);
        graph[parent].num_children++;
    }
}

void aoStar(int node) {
    if (graph[node].visited) {
        return;
    }

    graph[node].visited = true;

    int min_heuristic = INT_MAX;
    int selected_child = -1;

    for (int i = 0; i < graph[node].num_children; i++) {
        int child = graph[node].children[i];

        if (!graph[child].visited) {
            // Expand the child first
            aoStar(child);
        }

        // OR connection
        if (graph[node].type[i] == 0) {
            int current_heuristic = graph[child].heuristic + graph[node].cost[i];
            if (current_heuristic < min_heuristic) {
                min_heuristic = current_heuristic;
                selected_child = i;
            }
        }
        // AND connection
        else if (graph[node].type[i] == 1) {
            int total_cost = 0;

            for (int j = 0; j < graph[node].num_children; j++) {
                if (graph[node].type[j] == 1) {
                    int sibling = graph[node].children[j];
                    total_cost += graph[sibling].heuristic + graph[node].cost[j];
                }
            }
            if (total_cost < min_heuristic) {
                min_heuristic = total_cost;
                selected_child = i;
            }
        }
    }

    if (min_heuristic != INT_MAX) {
        graph[node].heuristic = min_heuristic;
        graph[node].optimal = selected_child;
    }
}

void printOptimalPath(int node) {
    cout << node << " ";
    if (graph[node].num_children == 0) {
        // It's a leaf node
        return;
    }

    int optimal_child = graph[node].optimal;

    if (graph[node].type[optimal_child] == 0) {
        printOptimalPath(graph[node].children[optimal_child]);
    }
    else if (graph[node].type[optimal_child] == 1) {
        for (int i = 0; i < graph[node].num_children; i++) {
            if (graph[node].type[i] == 1) {
                printOptimalPath(graph[node].children[i]);
            }
        }
    }
}

int main() {
    inputGraph();
    aoStar(0);

    cout << "\nUpdated Heuristics:\n";
    for (int i = 0; i < num_nodes; i++) {
        cout << "Node " << i << ": Heuristic = " << graph[i].heuristic << endl;
    }

    cout << "\nOptimal Path: ";
    printOptimalPath(0);
    cout << "\n";

    return 0;
}
