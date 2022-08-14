/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        score += s[0] == '0' ? 1 : 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') score += 1;
        }
        int maxScore = score;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') score += 1;
            else score -= 1;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
// @lc code=end


