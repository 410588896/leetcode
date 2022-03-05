/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int len2 = 0, len5 = 0;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num % 5 == 0) {
                len5++;
                num /= 5;
            }
            num = i;
            while (num % 2 == 0) {
                len2++;
                num /= 2;
            }
        }
        return min(len2, len5);
    }
};
