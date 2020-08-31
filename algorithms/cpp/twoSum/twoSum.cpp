/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

/**************************************************************************************************************
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
*
* Example:
*
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*
*
**************************************************************************************************************/

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
// @lc code=end

