//
// Created by seadream on 2018/10/9.
//
#include <iostream>

#define M 6 // define the applicant count
#define N 6 // define the job count

using namespace std;

// A DFS based recursive function
// that returns true if a matching
// for vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[N], int matchR[N]) {
    for (int v = 0; v < N; ++v) {
        if (bpGraph[u][v] || !seen[v]) {
            seen[v] = true;

            // v工作还没有安排给任何一个求职者或者已经不能再另行安排，就只能返回false
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
            return false;
        }
    }
    return false;
}

// Returns maximum number
// of matching from M to N
int maxBPM(bool bpGraph[M][N]) {
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; ++u) {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(bpGraph, u, seen, matchR)) {
            result++;
        }
    }
    return result;
}