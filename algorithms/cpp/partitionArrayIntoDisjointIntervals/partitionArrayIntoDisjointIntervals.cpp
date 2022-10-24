/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int curMax = nums[0], leftMax = nums[0];
        int left = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            curMax = max(curMax, nums[i]);
            if (leftMax > nums[i]) {
                leftMax = curMax;
                left = i;
            }
        }
        return left + 1;
    }
};
// @lc code=end


