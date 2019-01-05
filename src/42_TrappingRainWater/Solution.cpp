//
// Created by seadream on 2019/1/4.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// 出错情况[5,5,1,7,1,1,5,2,7,6]
class Solution {
public:
    int trap(vector<int>& height) {
        int contain = 0;
        if (height.size() <= 2) {
            return contain;
        }
        int leftMost = 0;
        int rightMost = height.size()-1;
        // 第一先找到从左边的找到最高位，不考虑
        while (height[leftMost] <= height[leftMost+1]) {
            leftMost++;
        }
        // 第二从右边找到最高位
        while (height[rightMost] <= height[rightMost-1]) {
            rightMost--;
        }
        while (leftMost < rightMost) {
            if (height[leftMost] < height[rightMost]) { // 右边的要高一些
                int leftAhead = leftMost+1;
                while (height[leftAhead] < height[leftMost] && leftAhead <= height.size()-1) {
                    contain += height[leftMost]-height[leftAhead];
                    leftAhead++;
                }
                leftMost = leftAhead;
            }  else { // 左边要高一些或者左右相等
                int rightAhead = rightMost-1;
                while (height[rightAhead] < height[rightMost] && rightAhead >= 0) {
                    contain += height[rightMost] - height[rightAhead];
                    rightAhead--;
                }
                rightMost = rightAhead;
            }
        }
        return contain;
    }
};
