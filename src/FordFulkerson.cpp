//
// Created by seadream on 2018/10/10.
//

#include <iostream>
#include <queue>

// Number of vertices in given graph
#define V 6

using namespace std;


/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[V]) {
    queue<int> q;

    bool visited[V];
    memset(visited, 0, sizeof(visited));

    parent[s] = -1;

    q.push(s);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return visited[t];

}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t) {
    // Residual graph where rGraph[i][j] indicates
    // residual capacity of edge from i to j (if there
    // is an edge. If rGraph[i][j] is 0, then there is not)
    int u, v;
    int rGraph[V][V];

    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    // There is no flow initially
    int max_flow = 0;

    int parent[V];
    memset(parent, 0, V);

    while (bfs(rGraph, s, t, parent)) {
        int min_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            min_flow = min(min_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= min_flow;
            rGraph[v][u] += min_flow; // 反向增加
        }
        max_flow += min_flow;
    }
    // Augment the flow while there is path from source to sink

    return max_flow;
}





