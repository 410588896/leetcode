/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

/**********************************
* 
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return the minimum cuts needed for a palindrome partitioning of s.
* 
*  
* 
* Example 1:
* 
* Input: s = "aab"
* Output: 1
* Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
* Example 2:
* 
* Input: s = "a"
* Output: 0
* Example 3:
* 
* Input: s = "ab"
* Output: 1
*  
* 
* Constraints:
* 
* 1 <= s.length <= 2000
* s consists of lower-case English letters only.
* 
**********************************/

// @lc code=start
class Solution {
private:
    void preProcess(vector<vector<bool> > &can, string s, int left, int right, int len) {
        while (left >= 0 && right < len && s[left] == s[right]) {
            can[left][right] = true;
            left--;
            right++;
        }
        return;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > can(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            preProcess(can, s, i, i, n);
            preProcess(can, s, i, i + 1, n);
        }
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (can[j][i]) {
                    dp[i + 1] = min(dp[j] + 1, dp[i + 1]);
                }
            }
        }
        return dp[n] - 1;
    }
};
// @lc code=end


