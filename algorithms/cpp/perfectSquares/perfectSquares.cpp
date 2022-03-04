/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

/*****************************************
* 
* Given an integer n, return the least number of perfect square numbers that sum to n.
* 
* A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
* 
*  
* 
* Example 1:
* 
* Input: n = 12
* Output: 3
* Explanation: 12 = 4 + 4 + 4.
* Example 2:
* 
* Input: n = 13
* Output: 2
* Explanation: 13 = 4 + 9.
*  
* 
* Constraints:
* 
* 1 <= n <= 104
* 
*****************************************/

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        int maxN = static_cast<int>(sqrt(n)) + 1;
        vector<int> sqrtNums(maxN);
        for (int i = 1; i < maxN; i++) {
            sqrtNums[i] = i * i;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < maxN; j++) {
                if (i < sqrtNums[j]) break;
                dp[i] = min(dp[i], dp[i - sqrtNums[j]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

