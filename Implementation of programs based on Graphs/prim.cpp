#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

vector<Edge> primMST(vector<vector<Edge>>& adjList) {
    int n = adjList.size();
    vector<Edge> mst;
    vector<bool> visited(n, false);

    auto cmp = [](const Edge& e1, const Edge& e2) { return e1.weight > e2.weight; };
    multiset<Edge, decltype(cmp)> minHeap(cmp);

    int startNode = 0; 

    visited[startNode] = true;
    for (const Edge& edge : adjList[startNode])
        minHeap.insert(edge);

    while (!minHeap.empty()) {
        Edge minEdge = *minHeap.begin();
        minHeap.erase(minHeap.begin());

        if (visited[minEdge.to])
            continue;

        mst.push_back(minEdge);
        visited[minEdge.to] = true;

        for (const Edge& edge : adjList[minEdge.to]) {
            if (!visited[edge.to])
                minHeap.insert(edge);
        }
    }

    return mst;
}

void addEdge(vector<vector<Edge>>& adjList, int u, int v, int weight) {
    adjList[u].push_back(Edge(v, weight));
    adjList[v].push_back(Edge(u, weight)); 
}

void buildGraph(vector<vector<Edge>>& adjList) {
    int n, m; 
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
   
