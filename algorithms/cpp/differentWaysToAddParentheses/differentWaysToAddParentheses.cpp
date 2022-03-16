/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;
        int n = expression.size();
        if (n == 1 || n == 2) {
            ways.push_back(stoi(expression));
            return ways;
        }
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> leftWays = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightWays = diffWaysToCompute(expression.substr(i + 1));
                for (auto & left : leftWays) {
                    for (auto & right : rightWays) {
                        switch (c) {
                            case '+': ways.push_back(left + right); break;
                            case '-': ways.push_back(left - right); break;
                            case '*': ways.push_back(left * right); break;
                        }
                    }
                }
            }
        }
        return ways;
    }
};
