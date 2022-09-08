/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1; i < n - k; i++) {
            res.push_back(i);
        }
        for (int i = n - k, j = n; i <= j; i++, j--) {
            res.push_back(i);
            if (i != j) {
                res.push_back(j);
            }
        }
        return res;
    }
};
// @lc code=end


