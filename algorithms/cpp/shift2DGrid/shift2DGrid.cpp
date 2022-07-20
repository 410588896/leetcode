/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> newGrid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = (i * m + j + k) % (m * n);
                newGrid[index / m][index % m] = grid[i][j];
            }
        }
        return newGrid;
    }
};
// @lc code=end


