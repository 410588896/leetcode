/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        long total = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        long sum = 0;
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(nums[i]);
            sum += nums[i];
            if (sum > total - sum) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end


