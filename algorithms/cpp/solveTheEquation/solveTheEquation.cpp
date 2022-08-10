/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int val = 0, sign1 = 1, factor = 0;
        int idx = 0, n = equation.size();
        while (idx < n) {
            if (equation[idx] == '=') {
                sign1 = -1;
                idx++;
                continue;
            }
            int sign2 = sign1, number = 0;
            bool valid = false;
            if (equation[idx] == '+' || equation[idx] == '-') {
                sign2 = equation[idx] == '-' ? -sign1 : sign1;
                idx++;
            }
            while (idx < n && isdigit(equation[idx])) {
                number = number * 10 + equation[idx] - '0';
                idx++;
                valid = true;
            }
            if (idx < n && equation[idx] == 'x') {
                factor += valid ? sign2 * number : sign2;
                idx ++;
            } else {
                val += number * sign2;
            }
        }
        if (factor == 0 && val == 0) {
            return "Infinite solutions";
        }
        if (factor == 0 && val != 0) {
            return "No solution";
        }
        return "x=" + to_string(-val / factor); 
    }
};
// @lc code=end


