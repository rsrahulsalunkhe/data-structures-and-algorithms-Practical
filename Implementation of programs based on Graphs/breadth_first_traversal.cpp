#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void BFS(int startNode, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void addEdge(unordered_map<int, vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); 
}

void buildGraph(unordered_map<int, vector<int>>& adjList) {
    int n, m; 
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v format, 0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }
}

int main() {
    unordered_map<int, vector<int>> adjList;
    buildGraph(adjList);

    int startNode;
    cout << "Enter the starting node for Breadth-First Traversal: ";
    cin >> startNode;

    int totalNodes = adjList.size();
    vector<bool> visited(totalNodes, false);

    cout << "Breadth-First Traversal starting from node " << startNode << ": ";
    BFS(startNode, adjList, visited);
    cout << endl;

    return 0;
}
