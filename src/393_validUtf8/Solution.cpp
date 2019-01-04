//
// Created by seadream on 2019/1/3.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); i++) { // data 中的每个数据都必须是小于256的数据
            if (data[i] < 0b10000000) {
                continue;
            } else {
                int val = data[i];
                int cnt = 0;

                for (int j = 7; j >= 1; --j) {
                    if (val >= pow(2, j)) ++cnt;
                    else break;
                    val -= pow(2, j);
                }
                if (cnt == 1) return false;
                for (int j = i + 1; j < i + cnt; j++) {
                    if ((data[j] & 0b11000000) != 0b10000000) {
                        return false;
                    }
                }
                i += cnt - 1;
            }
        }
        return true;
    }
};