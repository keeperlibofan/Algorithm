//
// Created by seadream on 2019-01-07.
// n x n 的二维矩阵，所以是正方形矩阵。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i=0, j=n-1; i<j; i++,j--)
        {
            for (int k=0; k<n; k++)
                swap(matrix[k][i], matrix[k][j]);
        }
    }
};

