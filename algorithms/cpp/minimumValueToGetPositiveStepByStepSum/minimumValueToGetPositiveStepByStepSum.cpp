/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (minSum > sum) {
                minSum = sum;
            }
        }
        if (minSum >= 0) return 1;
        else return -minSum + 1;
    }
};
// @lc code=end


