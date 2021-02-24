/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

/*******************************************
* 
* Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
* 
*  
* 
* Example 1:
* 
* Input: target = 7, nums = [2,3,1,2,4,3]
* Output: 2
* Explanation: The subarray [4,3] has the minimal length under the problem constraint.
* Example 2:
* 
* Input: target = 4, nums = [1,4,4]
* Output: 1
* Example 3:
* 
* Input: target = 11, nums = [1,1,1,1,1,1,1,1]
* Output: 0
*  
* 
* Constraints:
* 
* 1 <= target <= 109
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 105
*  
* 
* Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
* 
*******************************************/

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int start = 0, end = 0;
        int sum = 0;
        int res = INT_MAX;
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                res = min(res, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end


