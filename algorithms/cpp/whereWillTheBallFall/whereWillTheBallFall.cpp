/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(grid[0].size(), -1);
        for (int i = 0; i < n; i++) {
            int col = i;
            for (int j = 0; j < m; j++) {
                int dir = grid[j][col];
                col += dir;
                if (col < 0 || col == n || grid[j][col] != dir) {
                    col = -1;
                    break;
                }
            }
            res[i] = col;
        }
        return res;
    }
};
