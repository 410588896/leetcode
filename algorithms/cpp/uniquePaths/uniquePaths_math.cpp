/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

/*******************************************
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* 
* The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* 
* How many possible unique paths are there?
* 
*  
* 
* Example 1:
* 
* 
* Input: m = 3, n = 7
* Output: 28
* Example 2:
* 
* Input: m = 3, n = 2
* Output: 3
* Explanation:
* From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
* 1. Right -> Down -> Down
* 2. Down -> Down -> Right
* 3. Down -> Right -> Down
* Example 3:
* 
* Input: m = 7, n = 3
* Output: 28
* Example 4:
* 
* Input: m = 3, n = 3
* Output: 6
*  
* 
* Constraints:
* 
* 1 <= m, n <= 100
* It's guaranteed that the answer will be less than or equal to 2 * 109.
* 
*******************************************/

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        double res = 1.0;
        for (int i = 1; i < m; i++) {
            res = res * (N - (m - 1) + i) / i;
        }
        return (int)res;
    }
};
// @lc code=end


