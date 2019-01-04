//
// Created by seadream on 2019/1/2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 样例：[-2,1,-3,4,-1,2,1,-5,4],
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];
        int result = nums[0];

        auto n = nums.size();
        vector<int> sums(n, 0);
        sums[0] = result;
        for (int i = 1; i < n; i++) {
            sums[i] = max(nums[i], sums[i-1]+nums[i]);
            result = max(result, sums[i]);
        }
        return result;
    }
};
