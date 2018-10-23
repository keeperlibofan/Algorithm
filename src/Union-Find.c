//
// Created by seadream on 2018/10/23.
//

// Union-Find 算法
// Union by rank(technique) and path compression

#include <stdlib.h>

struct Edge {
    int src, dest;
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i ) {
    // find root and make root as parent of i(path compression)
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

struct GraphUF {
    int V, E;

    struct Edge* edges;
};

struct GraphUF* createGraph(int V, int E) {
    auto graph = (struct GraphUF*) malloc(sizeof(struct GraphUF));
    graph->V = V;
    graph->E = E;

    graph->edges = (struct Edge*) malloc(sizeof(struct Edge) * E);

    return graph;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    // ranks 是相同的， 使一个为root，然后提高其rank
    else {
        subsets[xroot].parent = yroot;
        subsets[yroot].rank++;
    }
}