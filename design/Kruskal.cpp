//
// Created by seadream on 2018/10/14.
//

// 是一种贪心算法
// 这道题我们继续使用优先队列来解决 first in largest out:具有优先权限最高的才会被最先弹出队列

// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
#include <iostream>
#include <vector>

using namespace std;

// 创建整型数对的捷径
typedef pair<int, int> iPair;

struct Graph {
    // V 是顶点数目，E是边缘数目
    int V, E;
    std::vector< std::pair<int, iPair> > edges;

    // Constructor
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    // 查找最小生成树通过Kruskal的MST算法
    int KruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets {
    int *parent, *rnk;
    int n;

    // 构造器
    DisjointSets(int n) {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        // 初始化所有的点都在不一样的set中并且rank设置为0
        for (int i = 0; i <= n; i++) {

            rnk[i] = 0;
            // 每个元素的parent就是他们自己
            parent[i] = i;
        }
    }

    // Path Compression
    int find(int u) {
        // 使node的parent在path中
        if (u != parent[u])
            parent[u] = find(parent[u]); // 这里递归了
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y) {
        x = find(x), y = find(y);


    }
};

// Functions returns weight of MST
int Graph::KruskalMST() {
    int mst_wt = 0; // 初始化结果

    // 基于边权重从小到大排列边
    sort(edges.begin(), edges.end());

    // 创建一个不相交的集合
    DisjointSets ds(V);

    vector<pair<int, iPair>>::iterator it;
    for (it=edges.begin(); it != edges.end(); it++) {
        int u = it->second.first; // 迭代器通过->来引用
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // check 是否选中的边创造出了一个圈圈（当u和v处于同一个set时，就会产生圆圈）
    }

}

//struct Edge {
//    int src, dist, weight;
//    // 重载运算符只能使用 < 符号，如果换成 > 符号就会报错C2784错误
//    // 原因就是默认的queue插入是从大到小，调用que的push函数时会因为找不到相应的操作符因而报错
//    friend bool operator < (Edge e1, Edge e2) {
//        return e1.weight > e2.weight;
//    }
//    Edge(int x, int y, int z): src(x) , dist(y), weight(z) {}
//};
