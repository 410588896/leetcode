/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        if (n < 4) return 1;
        string s(n, '0');
        s[0] = '1', s[1] = '2', s[2] = '2';
        int i = 2, j = 3;
        int res = 1;
        while (j < n) {
            int size = s[i] - '0';
            int num = 3 - (s[j - 1] - '0');
            while (size > 0 && j < n) {
                s[j] = num + '0';
                if (s[j] == '1') {
                    res ++;
                }
                j++;
                size--;
            }
            ++i;
        }
        return res;
    }
};
// @lc code=end


