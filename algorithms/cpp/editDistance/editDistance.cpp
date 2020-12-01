/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

/***************************************
* 
* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
* 
* You have the following three operations permitted on a word:
* 
* Insert a character
* Delete a character
* Replace a character
*  
* 
* Example 1:
* 
* Input: word1 = "horse", word2 = "ros"
* Output: 3
* Explanation: 
* horse -> rorse (replace 'h' with 'r')
* rorse -> rose (remove 'r')
* rose -> ros (remove 'e')
* Example 2:
* 
* Input: word1 = "intention", word2 = "execution"
* Output: 5
* Explanation: 
* intention -> inention (remove 't')
* inention -> enention (replace 'i' with 'e')
* enention -> exention (replace 'n' with 'x')
* exention -> exection (replace 'n' with 'c')
* exection -> execution (insert 'u')
*  
* 
* Constraints:
* 
* 0 <= word1.length, word2.length <= 500
* word1 and word2 consist of lowercase English letters.
* 
***************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m * n == 0) return m + n;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int n_1 = dp[i - 1][j] + 1;
                int m_1 = dp[i][j - 1] + 1;
                int n_m_1 = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(n_1, min(m_1, n_m_1));
            }
        }
        return dp[m][n];
    }
};


