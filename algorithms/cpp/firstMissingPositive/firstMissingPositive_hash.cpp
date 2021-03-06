/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

/**********************************************
* 
* Given an unsorted integer array nums, find the smallest missing positive integer.
* 
* Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,2,0]
* Output: 3
* Example 2:
* 
* Input: nums = [3,4,-1,1]
* Output: 2
* Example 3:
* 
* Input: nums = [7,8,9,11,12]
* Output: 1
*  
* 
* Constraints:
* 
* 0 <= nums.length <= 300
* -231 <= nums[i] <= 231 - 1
* 
**********************************************/

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int &num : nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
// @lc code=end


