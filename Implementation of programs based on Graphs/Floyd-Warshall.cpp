#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

void floydWarshall(unordered_map<int, vector<pair<int, int>>>& adjList, vector<vector<int>>& distances) {
    int n = adjList.size();
    distances.assign(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        distances[i][i] = 0;

    for (const auto& entry : adjList) {
        int u = entry.first;
        for (const auto& neighbor : entry.second) {
            int v = neighbor.first;
            int weight = neighbor.second;
            distances[u][v] = weight;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[i][k] != INF && distances[k][j] != INF)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

void addEdge(unordered_map<int, vector<pair<int, int>>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight});
}

void buildGraph(unordered_map<int, vector<pair<int, int>>>& adjList) {
    int n, m; 
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v weight format, 0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(adjList, u, v, weight);
    }
}

int main() {
    unordered_map<int, vector<pair<int, int>>> adjList;
    buildGraph(adjList);

    int totalNodes = adjList.size();
    vector<vector<int>> distances;

    floydWarshall(adjList, distances);

    cout << "Shortest distances between all pairs of nodes:" << endl;
    for (int i = 0; i < totalNodes; i++) {
        for (int j = 0; j < totalNodes; j++) {
            if (distances[i][j] == INF)
                cout << "Node " << i << " to Node " << j << ": Not reachable" << endl;
            else
                cout << "Node " << i << " to Node " << j << ": " << distances[i][j] << endl;
        }
    }

    return 0;
}
