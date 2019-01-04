//
// Created by seadream on 2019/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.size() == 0) {
            return 0;
        }
        vector<int> dp(envelopes.size(), 1);
        sort(envelopes.begin(), envelopes.end());
        auto n = envelopes.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};