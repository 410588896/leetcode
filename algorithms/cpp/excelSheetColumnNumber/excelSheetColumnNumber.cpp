/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        long base = 1;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            res += base * (columnTitle[i] - 'A' + 1);
            base *= 26;
        }
        return res;
    }
};
