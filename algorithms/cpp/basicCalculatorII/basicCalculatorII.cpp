/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

/************************************
* 
* Given a string s which represents an expression, evaluate this expression and return its value. 
* 
* The integer division should truncate toward zero.
* 
*  
* 
* Example 1:
* 
* Input: s = "3+2*2"
* Output: 7
* Example 2:
* 
* Input: s = " 3/2 "
* Output: 1
* Example 3:
* 
* Input: s = " 3+5 / 2 "
* Output: 5
*  
* 
* Constraints:
* 
* 1 <= s.length <= 3 * 105
* s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
* s represents a valid expression.
* All the integers in the expression are non-negative integers in the range [0, 231 - 1].
* The answer is guaranteed to fit in a 32-bit integer.
* 
************************************/

// @lc code=start
class Solution {
private:
    deque<char> deOp;
    deque<int> deNum;
    int cal(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        if (op == '/') return a / b;
        return INT_MIN;
    }
public:
    int calculate(string s) {
        int opFlag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*' || s[i] == '/') {
                opFlag = 1;
                deOp.push_back(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                deOp.push_back(s[i]);
            } else if (s[i] == ' ') continue;
            else {
                int l = i;
                while (l < s.size() && s[l] == ' ') l++;
                int r = l + 1;
                while (r < s.size() && s[r] >= '0' && s[r] <= '9') r++;
                int num = atoi(s.substr(l, r - l).c_str());
                deNum.push_back(num);
                i = r - 1;
                if (opFlag == 1) {
                    opFlag = 0;
                    int a = deNum.back(); deNum.pop_back();
                    int b = deNum.back(); deNum.pop_back();
                    char op = deOp.back(); deOp.pop_back();
                    int c = cal(b, a, op);
                    deNum.push_back(c);
                }
            }
        }
        while (!deOp.empty()) {
            int a = deNum.front(); deNum.pop_front();
            int b = deNum.front(); deNum.pop_front();
            char op = deOp.front(); deOp.pop_front();
            int c = cal(a, b, op);
            deNum.push_front(c);
        }
        return deNum.front();
    }
};
// @lc code=end


