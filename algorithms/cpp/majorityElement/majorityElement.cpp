/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                res = num;
                count++;
            } else if (num == res) {
                count ++;
            } else {
                count --;
            }
        }
        return res;
    }
};
