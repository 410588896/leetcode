/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

/********************************************************
* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
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
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left, ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [start1, end1] = expandAroundCenter(s, i, i);
            auto [start2, end2] = expandAroundCenter(s, i, i+1);
            if ((end1 - start1) > (end - start)) {
                end = end1, start = start1;
            }
            if ((end2 - start2) > (end - start)) {
                end = end2, start = start2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
// @lc code=end

