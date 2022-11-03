/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size();
        if (n < m) {
            return 0;
        }
        int res = 0;

        vector<int> f(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (i - m < 0) continue;
            if (sequence.substr(i - m, m) == word ){
                f[i] = f[i - m] + 1;
            }
            res = max(res, f[i]);
        }
        
        return res;
    }
};
// @lc code=end


