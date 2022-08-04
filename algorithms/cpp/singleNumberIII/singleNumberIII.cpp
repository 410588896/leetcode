/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto num : nums) {
            x ^= num;
        }
        x = x == INT_MIN ? x : (x & (-x));
        int num1 = 0, num2 = 0;
        for (auto num : nums) {
            if (x & num) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        return {num1, num2};
    }
};
// @lc code=end


