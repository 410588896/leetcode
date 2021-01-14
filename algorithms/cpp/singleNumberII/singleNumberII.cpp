/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

/********************************
* 
* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
* 
*  
* 
* Example 1:
* 
* Input: nums = [2,2,3,2]
* Output: 3
* Example 2:
* 
* Input: nums = [0,1,0,1,0,1,99]
* Output: 99
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 3 * 104
* -231 <= nums[i] <= 231 - 1
* Each element in nums appears exactly three times except for one element which appears once.
*  
* 
* Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
* 
********************************/

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for (auto num : nums) {
            seenOnce = (~seenTwice) & (seenOnce ^ num);
            seenTwice = (~seenOnce) & (seenTwice ^ num);
        }
        return seenOnce;
    }
};
// @lc code=end


