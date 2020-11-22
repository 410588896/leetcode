/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

/*******************************************
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* 
* The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* 
* Now consider if some obstacles are added to the grids. How many unique paths would there be?
* 
* An obstacle and space is marked as 1 and 0 respectively in the grid.
* 
*  
* 
* Example 1:
* 
* 
* Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
* Output: 2
* Explanation: There is one obstacle in the middle of the 3x3 grid above.
* There are two ways to reach the bottom-right corner:
* 1. Right -> Right -> Down -> Down
* 2. Down -> Down -> Right -> Right
* Example 2:
* 
* 
* Input: obstacleGrid = [[0,1],[0,0]]
* Output: 1
*  
* 
* Constraints:
* 
* m == obstacleGrid.length
* n == obstacleGrid[i].length
* 1 <= m, n <= 100
* obstacleGrid[i][j] is 0 or 1.
* 
*******************************************/

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> f(n);
        f[0] = obstacleGrid[0][0] == 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};
// @lc code=end
