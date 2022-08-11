/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        int alphaNum = 0, digitNum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                digitNum ++;
            } else {
                alphaNum ++;
            }
        }
        if(abs(alphaNum - digitNum) > 1) return "";
        bool flag = digitNum > alphaNum;
        for (int i = 0, j = 1; i < s.size(); i += 2) {
            if (isdigit(s[i]) != flag) {
                while (isdigit(s[j]) != flag) {
                    j += 2;
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
// @lc code=end


