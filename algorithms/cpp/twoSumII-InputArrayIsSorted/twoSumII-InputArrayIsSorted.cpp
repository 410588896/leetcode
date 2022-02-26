/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l = 0, r = n - 1;
        while (l < r) {
            if (numbers[r] + numbers[l] == target) {
                return {l + 1, r + 1};
            } else if (numbers[r] + numbers[l] < target) {
                l++;
            } else {
                r--;
            }
        }
        return {-1, -1};
    }
};
