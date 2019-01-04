//
// Created by seadream on 2019/1/4.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int contain = 0;
        int leftMost = 0;
        int rightMost = height.size()-1;
        // 第一先找到从左边的找到最高位，不考虑
        while (height[leftMost] < height[leftMost+1]) {
            leftMost++;
        }
        // 第二从右边找到最高位
        while (height[rightMost] < height[rightMost-1]) {
            rightMost--;
        }
        while (leftMost < rightMost) {
            if (height[leftMost] < height[rightMost]) { // 右边的要高一些
                int leftAhead = leftMost+1;
                while (height[leftAhead] <= height[leftMost]) {
                    contain += height[leftMost]-height[leftAhead];
                    leftAhead++;
                }
                leftMost = leftAhead;
            }  else { // 左边的要高一些
                int rightAhead = rightMost-1;
                while (height[rightAhead] <= height[rightMost]) {
                    contain += height[rightMost] - height[rightAhead];
                    rightAhead--;
                }
                rightMost = rightAhead;
            }
        }
        return contain;
    }
};
