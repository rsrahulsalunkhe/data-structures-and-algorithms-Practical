#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

vector<Edge> kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Edge> mst;
    DisjointSet dsu(n);

    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            mst.push_back(edge);
            dsu.unite(edge.u, edge.v);
        }
    }

    return mst;
}

void buildGraph(vector<Edge>& edges) {
    int n, m; 
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> m;

    cout << "Enter " << m << " edges (u v weight format, 0-based indexing):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }
}

int main() {
    vector<Edge> edges;
    buildGraph(edges);

    int totalNodes = edges.size(); 

    vector<Edge> mst = kruskalMST(edges, totalNodes);

    cout << "Minimum Spanning Tree (MST) using Kruskal's algorithm:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.u << " -- " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
