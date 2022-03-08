/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negtive = num < 0;
        num = abs(num);
        string digits;
        while (num > 0) {
            digits.push_back(num % 7 + '0');
            num /= 7;
        }
        if (negtive) {
            digits.push_back('-');
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
