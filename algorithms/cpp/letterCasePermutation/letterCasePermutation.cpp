/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
private: 
    void dfs(string &s, int pos, vector<string> &res) {
        while (pos < s.size() && isdigit(s[pos])) {
            pos ++;
        }
        if (pos == s.size()) {
            res.push_back(s);
            return;
        }
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }
};
// @lc code=end


