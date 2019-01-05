//
// Created by seadream on 2019-01-05.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
         vector<vector<int> > res;
         vector<int> out;
         vector<int> visited(nums.size(), 0);
         permuteDFS(nums, 0, visited, out, res);
         return res;
    }

    void permuteDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level == num.size()) {
            res.push_back(out);
        } else {
            for (int i = 0; i < num.size(); i++) {
                if (visited[i] == 0) {
                    visited[i] = 0;
                    out.push_back(num[i]);
                    permuteDFS(num, level+1, visited, out, res);
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};
