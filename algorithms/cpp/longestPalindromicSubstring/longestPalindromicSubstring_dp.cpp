/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

/********************************************************
* Given a string s, find the longest palindromic substring in s. 
* You may assume that the maximum length of s is 1000.
*
* Example 1:
* 
* Input: "babad"
* Output: "bab"
* Note: "aba" is also a valid answer.
* Example 2:
* 
* Input: "cbbd"
* Output: "bb"
*
*********************************************************/

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
                }
                if ((l + 1 > ret.size()) && dp[i][j]) {
                    ret = s.substr(i, l + 1);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

