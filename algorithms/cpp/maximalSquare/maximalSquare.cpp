/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

/***************************************
* 
* Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
* 
*  
* 
* Example 1:
* 
* 
* Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
* Output: 4
* Example 2:
* 
* 
* Input: matrix = [["0","1"],["1","0"]]
* Output: 1
* Example 3:
* 
* Input: matrix = [["0"]]
* Output: 0
*  
* 
* Constraints:
* 
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is '0' or '1'.
* 
***************************************/

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    }
                    maxSide = max(dp[i][j], maxSide);
                }
            }
        }
        return maxSide * maxSide;
    }
};
// @lc code=end


