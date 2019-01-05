//
// Created by seadream on 2019-01-05.
// 挺难得这道题还是，要想出来不容易
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteDFS(nums, visited, out, res);
        return res;
    }
    // 第一次参数是传入的值，不能改变 DFS深度优先
    void permuteDFS(vector<int> &nums, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (out.size() == nums.size()) { // 只有level和nums的长度一样out才能被添加到res
            res.push_back(out);
        } else { // 长度不都
            for (int i = 0; i < nums.size(); i++) {
                if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue; // 这个地方比较难写出，可以自己画一个深度优先树
                visited[i] = 1;
                out.push_back(nums[i]);
                permuteDFS(nums, visited, out, res);
                out.pop_back();
                visited[i] = 0; // 回溯算法
            }
        }
    }
};
