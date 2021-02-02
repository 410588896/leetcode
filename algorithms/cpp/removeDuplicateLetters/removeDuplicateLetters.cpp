/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

/************************************
* 
* Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
* 
* Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
* 
*  
* 
* Example 1:
* 
* Input: s = "bcabc"
* Output: "abc"
* Example 2:
* 
* Input: s = "cbacdcbc"
* Output: "acdb"
*  
* 
* Constraints:
* 
* 1 <= s.length <= 104
* s consists of lowercase English letters.
* 
************************************/

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size() <= 1) return s;
        vector<int> num(26, 0), vis(26, 0);
        for (auto ch : s) {
            num[ch - 'a']++;
        }
        string res;
        for (auto ch : s) {
            if (!vis[ch - 'a']) {
                while(!res.empty() && res.back() > ch) {
                    if (num[res.back() - 'a'] > 0) {
                        vis[res.back() - 'a'] = 0;
                        res.pop_back();
                    } else {
                        break;
                    }
                }
                res.push_back(ch);
                vis[ch - 'a'] = 1;
            }
            num[ch - 'a'] -= 1;
        }
        return res;
    }
};
// @lc code=end


