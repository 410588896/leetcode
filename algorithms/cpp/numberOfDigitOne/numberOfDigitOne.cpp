/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        if (m == 1) return n > 0 ? 1 : 0;
        vector<int> ps(m, 0);
        vector<int> ss(m, 0);
        ss[0] = atoi(s.substr(1, m - 1).c_str());
        ps[m - 1] = atoi(s.substr(0, m - 1).c_str());
        for (int i = 1; i < m - 1; i++) {
            ss[i] = atoi(s.substr(i + 1, m - i - 1).c_str());
            ps[i] = atoi(s.substr(0, i).c_str());
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            int x = s[i] - '0';
            int len = m - i - 1;
            int prefix = ps[i];
            int suffix = ss[i];
            res += prefix * pow(10, len);
            if (x == 0) {
                continue;
            } else if (x == 1) {
                res += suffix + 1;
            } else {
                res += pow(10, len);
            }
        }
        return res;
    }
};
// @lc code=end


