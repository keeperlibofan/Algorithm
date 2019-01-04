//
// Created by seadream on 2019/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        auto m = matrix.size();
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
        int ans = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = min(m - i + 1, n - j + 1); k > 0; k--) {

                }
            }
        }
    }
    int maximalSquare2(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        auto m = matrix.size();
        auto n = matrix[0].size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> sizes(m, vector<int>(n, 0)); // 子问题的解

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    // do nothing
                } else { // matrix[i][j] == '1'
                    if (i == 0 || j == 0) {
                        sizes[i][j] = matrix[i][j] - '0';
                    } else {
                        sizes[i][j] = min(min(sizes[i][j - 1],
                                              sizes[i - 1][j]),
                                          sizes[i - 1][j - 1]) + 1;
                    }
                    ans = max(sizes[i][j] * sizes[i][j], ans);
                }
            }
        }
        return ans;
    }
};
