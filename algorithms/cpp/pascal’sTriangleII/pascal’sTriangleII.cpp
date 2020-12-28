/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

/*************************************
* 
* Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
* 
* Notice that the row index starts from 0.
* 
* 
* In Pascal's triangle, each number is the sum of the two numbers directly above it.
* 
* Follow up:
* 
* Could you optimize your algorithm to use only O(k) extra space?
* 
*  
* 
* Example 1:
* 
* Input: rowIndex = 3
* Output: [1,3,3,1]
* Example 2:
* 
* Input: rowIndex = 0
* Output: [1]
* Example 3:
* 
* Input: rowIndex = 1
* Output: [1,1]
*  
* 
* Constraints:
* 
* 0 <= rowIndex <= 33
* 
*************************************/

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp;
    }
};
// @lc code=end


