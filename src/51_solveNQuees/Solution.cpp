//
// Created by seadream on 2019-01-08.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        col_ = vector<int>(n, 0);
        diag1_ = vector<int>(2 * n - 1, 0);
        diag2_ = vector<int>(2 * n - 1, 0);
        nQueue(0);
        return vector<vector<string>>(sols_.begin(), sols_.end());
    }
private:
    vector<string> board_; // 当前棋盘
    set<vector<string>> sols_;
    vector<int> col_; // 只记录列
    vector<int> diag1_; // 左斜
    vector<int> diag2_; // 右斜
    int n;
    bool avaliable(int x, int y) {  // 给出明确的坐标, n 就是n_queue x是列的index，y是行的index
        return !col_[x] && !diag1_[x+y] && !diag2_[x-y+n-1];
    }
    // 更新棋盘
    void updateBoard(int x, int y, bool is_put) {
        col_[x] = is_put;
        diag1_[x+y] = is_put;
        diag2_[x-y+n-1] = is_put;
        board_[y][x] = is_put ? 'Q':'.';
    }
    // 在当前棋盘的第x行第y列放一个子
    void nQueue(const int y) {
        if (y == n) {
            // 如何深度复制一个 棋盘
            sols_.insert(board_);
            return;
        }
        for (int x = 0; x < n; x++) {
            if (avaliable(x, y)) {
                updateBoard(x, y, true);
                nQueue(y+1);
                updateBoard(x, y, false);
            } else {
                continue;
            }
        }
    }
};