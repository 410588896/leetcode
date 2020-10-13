/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

/************************************************
* 
* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
* 
*  
* 
* Example 1:
* 
* Input: nums = [-1,2,1,-4], target = 1
* Output: 2
* Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*  
* 
* Constraints:
* 
* 3 <= nums.length <= 10^3
* -10^3 <= nums[i] <= 10^3
* -10^4 <= target <= 10^4
* 
************************************************/

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;
        // 根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) {
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                } else {
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                }
            }
        }
        return best;
    }
};
// @lc code=end


