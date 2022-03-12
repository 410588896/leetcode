/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> dict1;
        unordered_map<char, char> dict2;
        for (int i = 0; i < s.size(); i++) {
            if (dict1.count(s[i]) && dict1[s[i]] != t[i] || 
            dict2.count(t[i]) && dict2[t[i]] != s[i]) {
                return false;
            }
            dict1[s[i]] = t[i];
            dict2[t[i]] = s[i];
        }
        return true;
    }
};
