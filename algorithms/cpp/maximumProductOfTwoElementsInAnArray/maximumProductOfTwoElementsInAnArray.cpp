/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = nums[0];
        int subMax = nums[1];
        if (maxNum < subMax) {
            swap(maxNum, subMax);
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > maxNum) {
                subMax = maxNum;
                maxNum = nums[i];
            } else if (nums[i] > subMax) {
                subMax = nums[i];
            }
        }
        return (maxNum - 1) * (subMax - 1);
    }
};
// @lc code=end


