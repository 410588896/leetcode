/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> dict(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dict[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (--dict[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


