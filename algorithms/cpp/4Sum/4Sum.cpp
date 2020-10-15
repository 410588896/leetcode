/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

/*******************************************************
* 
* Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
* 
* Notice that the solution set must not contain duplicate quadruplets.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,0,-1,0,-2,2], target = 0
* Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
* Example 2:
* 
* Input: nums = [], target = 0
* Output: []
*  
* 
* Constraints:
* 
* 0 <= nums.length <= 200
* -109 <= nums[i] <= 109
* -109 <= target <= 109
* 
*******************************************************/

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                int left = j + 1, right = n - 1;
                int tmpTarget = target - nums[i] - nums[j];
                while(left < right) {
                    if (nums[left] + nums[right] == tmpTarget) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left, --right;
                    } else if (nums[left] + nums[right] < tmpTarget) {
                        ++left;
                    } else {
                        --right;
                    }
                } 
            }
        }
        return res;
    }
};
// @lc code=end


