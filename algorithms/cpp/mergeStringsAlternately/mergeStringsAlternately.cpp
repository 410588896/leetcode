/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string res;
        res.reserve(m + n);
        while (i < m || j < n) {
            if (i < m) {
                res.push_back(word1[i++]);
            }
            if (j < n) {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};
// @lc code=end


