/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

/********************************************************************************************

* Given a string s, find the length of the longest substring without repeating characters.
*
* 
*
* Example 1:
*
* Input: s = "abcabcbb"
* Output: 3
* Explanation: The answer is "abc", with the length of 3.
* Example 2:
*
* Input: s = "bbbbb"
* Output: 1
* Explanation: The answer is "b", with the length of 1.
* Example 3:
*
* Input: s = "pwwkew"
* Output: 3
* Explanation: The answer is "wke", with the length of 3.
* Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
* Example 4:
*
* Input: s = ""
* Output: 0
*
*
* Constraints:
*
* 0 <= s.length <= 5 * 104
* s consists of English letters, digits, symbols and spaces.
*
*******************************************************************************************/

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int maxLength = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (map[s[i]] > start) {
                start = map[s[i]];
            }
            map[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};
// @lc code=end

