//
// Created by seadream on 2019-01-08.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 0;
        }
        double v = myPow(x, n/2);
        if (n % 2 == 0) {
            return v * v;
        } else { // 余下来的数字是1
            return v * v * x;
        }
    }
};
