//
// Created by seadream on 2019/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if (m == 0) {
            return 0;
        }
        auto n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int >> sums(m+1, vector<int>(n+1, 0));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sums[i][j] = matrix[i][j] - '0' \
                    + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

            }
        }

    }
};
