/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int premin = nums[0], res = -1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > premin) {
                res = max(res, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return res;
    }
};
