/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (auto & indice : indices) {
            rows[indice[0]]++;
            cols[indice[1]]++;
        }
        int oddX = 0, oddY = 0;
        for (auto row : rows) {
            if (row & 1 == 1) oddX++;
        }
        for (auto col : cols) {
            if (col & 1 == 1) oddY++;
        }
        return oddX * (n - oddY) + oddY * (m - oddX);
    }
};
// @lc code=end

