//
// Created by seadream on 2018/10/11.
//
#include <iostream>
#include <queue>
#include "FordFulkerson.cpp"
#include <set>

#define V 6

void dfs(int rGraph[V][V], int s, bool visited[V]) {
    visited[s] = true;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            dfs(rGraph, v, visited);
        }
    }
}

// return the min cut
int minCut(int graph[V][V], int s, int t) {
    if (s == t) {
        return true;
    }
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
    }

    bool visited[V];
    memset(visited, 0, sizeof(visited));
    dfs(rGraph, s, visited);

    int min_cut = 0;
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; ++v) {
            if (visited[u] && !visited[v]) {
                cout << u << "-" << v << ":" << graph[u][v] << endl;
                min_cut += graph[u][v];
            }
        }
    }

    return min_cut;
}