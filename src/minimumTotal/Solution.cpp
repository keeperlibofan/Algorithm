//
// Created by seadream on 2019/1/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto n = triangle.size();
        if (n <= 1) {
            return triangle[0][0];
        }
        vector<vector<int>> dp(2, vector<int>(n+1, INT_MAX)); // 修改为空间复杂度为O(n)的算法
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i+1; j++) { // 所有的点都属于合法的点
                if (j == 0) {
                    dp[1][j] = dp[0][j]+triangle[i][j];
                } else if (j == i) {
                    dp[1][j] = dp[0][j-1]+triangle[i][j];
                } else {
                    dp[1][j] = min(dp[0][j - 1], dp[0][j]) + triangle[i][j]; // 不考虑边界
                }
            }
            std::swap(dp[0], dp[1]); // 第0排的数据才是有效的数据
        }
        return *std::min_element(dp[0].begin(), dp[0].end());
    }
};
