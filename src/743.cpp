//
// Created by seadream on 2018/10/1.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution743 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        vector<vector<int>> edges(N+1, vector<int>(N+1, -1)); // 第一个是N+1
        vector<int> dist(N+1, INT_MAX);
        queue<int> q{{K}};
        dist[K] = 0;
        for (auto e : times) edges[e[0]][e[1]] = e[2];// 绘图
        while (!q.empty()) {
            unordered_set<int> visited;
            for (auto i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                for (auto v = 1; v < N+1; v++) {
                    if (edges[u][v] != -1 && dist[v] > dist[u] + edges[u][v]) {
                        if (!visited.count(v)) {
                            visited.insert(v);
                            q.push(v);
                        }
                        dist[v] = dist[u] + edges[u][v];
                    }
                }
            }
        }
        for (auto i = 1; i < N+1; i++) {
            res = max(res, dist[i]);
        }
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};