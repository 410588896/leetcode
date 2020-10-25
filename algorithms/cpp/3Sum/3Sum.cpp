/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

/**************************************************************
* 
* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
* 
* Notice that the solution set must not contain duplicate triplets.
* 
*  
* 
* Example 1:
* 
* Input: nums = [-1,0,1,2,-1,-4]
* Output: [[-1,-1,2],[-1,0,1]]
* Example 2:
* 
* Input: nums = []
* Output: []
* Example 3:
* 
* Input: nums = [0]
* Output: []
*  
* 
* Constraints:
* 
* 0 <= nums.length <= 3000
* -105 <= nums[i] <= 105
* 
**************************************************************/

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left, --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
// @lc code=end


