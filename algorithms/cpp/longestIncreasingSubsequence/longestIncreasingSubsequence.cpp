/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

/***************************************
* 
* Given an integer array nums, return the length of the longest strictly increasing subsequence.
* 
* A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
* 
*  
* 
* Example 1:
* 
* Input: nums = [10,9,2,5,3,7,101,18]
* Output: 4
* Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
* Example 2:
* 
* Input: nums = [0,1,0,3,2,3]
* Output: 4
* Example 3:
* 
* Input: nums = [7,7,7,7,7,7,7]
* Output: 1
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 2500
* -104 <= nums[i] <= 104
*  
* 
* Follow up:
* 
* Could you come up with the O(n2) solution?
* Could you improve it to O(n log(n)) time complexity?
* 
***************************************/

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end


