//
// Created by seadream on 2018/10/1.
//

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int row = key.length(), col = ring.length();
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        auto minCount = INT_MAX;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (ring[j] == key[i]) {
                    if (i == 0) {
                        dp[i][j] = min(abs(i-j), col-abs(i-j));
                    } else {
                        for (auto k = 0; k < col; k++) {
                            if (dp[i-1][k] != INT_MAX) {
                                dp[i][j] = min(dp[i][j], dp[i-1][k] + min(abs(k-j), col-abs(k-j)));
                            }
                        }
                    }
                }
                if (i == row-1) {
                    minCount = min(minCount, dp[i][j]);
                }
            }
        }
        return minCount + key.length();
    }
};
