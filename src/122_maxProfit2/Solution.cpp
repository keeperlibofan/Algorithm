//
// Created by seadream on 2019/1/2.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // L[i] 最低的买入价格 当前价格如果比上一轮价格高就保持不变 否则
        // P[i] 最大的增值
        // M[i] 最高价格
        // 状态转移方程
        const auto n = prices.size();
        if (n < 1)
            return 0;
        vector<int> lowPrice(n);
        vector<int> maxProfit(n);
        vector<int> maxPrice(n);
        lowPrice[0] = prices[0];
        maxPrice[0] = prices[0];
        maxProfit[0] = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < prices[i-1]) { // 如果降价了
                lowPrice[i] = prices[i];
                maxProfit[i] = maxProfit[i-1] + (maxPrice[i-1] - lowPrice[i-1]);
            } else {
                lowPrice[i] = lowPrice[i-1];
            }
        }
    }
    int maxProfit2(vector<int>& prices) {
        const auto n = prices.size();
        auto maxProfit = 0;
        auto lowPriceIndex = 0;
        for (int i = 1; i < n - 1; i++) {

        }
    }
    int maxProfit3(vector<int>& prices) {
        const size_t n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int max = 0;
        for (int i = 1; i < n; i++) {
            max += prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0;
        }
        return max;
    }
};

