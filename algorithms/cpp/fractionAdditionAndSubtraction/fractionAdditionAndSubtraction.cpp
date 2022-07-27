/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
class Solution {
public:
    string fractionAddition(string expression) {
        long long denominator = 1, numerator = 0;
        int idx = 0, n = expression.size();
        while (idx < n) {
            long long numeratorTmp = 0, sign = 1;
            if (expression[idx] == '-' || expression[idx] == '+') {
                sign = expression[idx] == '-' ? -1 : 1;
                idx++;
            }
            while (idx < n && isdigit(expression[idx])) {
                numeratorTmp = 10 * numeratorTmp + (expression[idx] - '0');
                idx++;
            }
            idx++;
            numeratorTmp = sign * numeratorTmp;
            long long denominatorTmp = 0;
            while (idx < n && isdigit(expression[idx])) {
                denominatorTmp = 10 * denominatorTmp + (expression[idx] - '0');
                idx++;
            }
            numerator = denominator * numeratorTmp + denominatorTmp * numerator;
            denominator *= denominatorTmp;
        }
        if (numerator == 0) {
            return "0/1";
        }
        long long g = gcd(abs(numerator), denominator);
        return to_string(numerator / g) + "/" + to_string(denominator / g);
    }
};
// @lc code=end


