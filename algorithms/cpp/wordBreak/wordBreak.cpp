/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

/*****************************************
* 
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
* 
* Note:
* 
* The same word in the dictionary may be reused multiple times in the segmentation.
* You may assume the dictionary does not contain duplicate words.
* Example 1:
* 
* Input: s = "leetcode", wordDict = ["leet", "code"]
* Output: true
* Explanation: Return true because "leetcode" can be segmented as "leet code".
* Example 2:
* 
* Input: s = "applepenapple", wordDict = ["apple", "pen"]
* Output: true
* Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
*              Note that you are allowed to reuse a dictionary word.
* Example 3:
* 
* Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
* Output: false
* 
*****************************************/

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto word : wordDict) {
            dict.insert(word);
        }
        int n = s.size();
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end


