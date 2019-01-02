//
// Created by seadream on 2019/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const auto n = prices.size();
        if (n < 1) return 0;
        // L[i] 到达第i个时最小的price
        // P[i] 到达第i个时最大的profit
        // [7,1,5,3,6,4]
        vector<int> minPrice(n);
        vector<int> maxProfit(n);
        minPrice[0] = prices[0];
        maxProfit[0] = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < minPrice[i-1]) {
                minPrice[i] = prices[i];
            } else {
                minPrice[i] = minPrice[i-1];
            }
            maxProfit[i] = max(maxProfit[i-1], prices[i] - minPrice[i-1]);
        }
        return maxProfit[n-1];
    }
    int maxProfit2(vector<int>& prices) {
        const auto n = prices.size();
        if (n < 1) return 0;

    }

};
