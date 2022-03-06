/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;
        int n = security.size();
        if (time < 0 || n == 0) return res;
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                res.push_back(i);
            }
        }
        return res;
    }
};
