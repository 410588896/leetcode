/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

/****************************************
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
* 
*  
* 
* Example 1:
* 
* 
* Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
* Output: 7
* Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
* Example 2:
* 
* Input: grid = [[1,2,3],[4,5,6]]
* Output: 12
*  
* 
* Constraints:
* 
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 200
* 0 <= grid[i][j] <= 100
* 
****************************************/

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rows = grid.size(), columns = grid[0].size();
        vector<vector<int> > dp(rows, vector<int>(columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) 
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < columns; i++) 
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};
// @lc code=end


