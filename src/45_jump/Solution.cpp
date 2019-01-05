//
// Created by seadream on 2019-01-05.
//
#include <iostream>
#include <vector>

using namespace std;

// 出错样例[2,3,1,1,4]
// 超出时间限制, 时间复杂度位O(n^2)

class Solution {
public:
    int jump(vector<int>& nums) {
        // L[i] 到达当前位置的最小跳数
        // res 用于记录最小条数值
        if (nums.size() == 1) {
            return 0;
        }
        int res = INT_MAX-100;
        vector<int> dp(nums.size(), INT_MAX-100);
        dp[0] = 0; // 因为起始点就在第一个位置
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= nums.size()-1) { // 数组最后一个位置
                    res = min(res, dp[i]+1);
                    break;
                } else { // 还没有跳出数组
                    dp[i+j] = min(dp[i]+1, dp[i+j]);
                }
            }
        }
        return res;
    }
    int jump2(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int step = 0;
        int index = 0;
        int len = nums.size();
        int p = 0;
        // 按照步伐地增来计算
        while (p <= len - 1) {
            if (p + nums[p] >= len - 1)
                return step + 1; // step 永远是当前最小的步伐
            int _max = -1; // 记录能到达的最远距离
            for (int i = p + 1; i <= p + nums[p]; ++i) { // 遍历从 p+1 到 p+nums[p]
                if (_max < i + nums[i]) { // 计算下一个步跳能达到的最远的位置
                    _max = i + nums[i];
                    index = i;
                }
            }
            step++;
            p = index;
        }
        return step;
    }
};
