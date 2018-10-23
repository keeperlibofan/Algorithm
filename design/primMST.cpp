//
// Created by seadream on 2018/10/11.
//
// 此题使用矩阵图
// 领接图也可以写写

#include <iostream>
#include <queue>
#define V 6

using namespace std;

struct HeapNode {
    int d, u; // u is the index
    bool operator < (const HeapNode& rhs) const {
        return d > rhs.d;
    }
    HeapNode(int x, int y): d(x), u(y) {}
};


// 最小生成树算法，贪心算法
int* primMST(int graph[V][V]) {
    int s = 0; // 起始点为0

    bool mstSet[V];
    memset(mstSet, false, V);

    // Key values used to pick minimum weight edge in cut
    int key[V];
    memset(key, INT_MAX, sizeof(key));

    // Array to store constructed MST
    int parent[V];
    memset(parent, 0, sizeof(parent));

    // 创建一个优先队列
    priority_queue<HeapNode> pq;
    pq.push((HeapNode){0, 0});

    parent[0] = -1;

    // 最小生成树，每遍历一次选择出一个最小的边
    while (!pq.empty()) {
        HeapNode node = pq.top();
        pq.pop();
        // 如果同样的点被推进了两遍
        if (mstSet[node.u]) {
            continue;
        }
        mstSet[node.u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[node.u][v] && !mstSet[v] && graph[node.u][v] < key[v]) {
                key[v] = graph[node.u][v];
                pq.push((HeapNode){key[v], v});
                parent[node.u] = v;
            }
        }
    }
    return parent;
}