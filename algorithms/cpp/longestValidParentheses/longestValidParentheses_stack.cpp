/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
*/

/**************************************
* 
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
* 
*  
* 
* Example 1:
* 
* Input: s = "(()"
* Output: 2
* Explanation: The longest valid parentheses substring is "()".
* Example 2:
* 
* Input: s = ")()())"
* Output: 4
* Explanation: The longest valid parentheses substring is "()()".
* Example 3:
* 
* Input: s = ""
* Output: 0
*  
* 
* Constraints:
* 
* 0 <= s.length <= 3 * 104
* s[i] is '(', or ')'.
* 
**************************************/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxRes = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxRes = max(maxRes, i - stk.top());
                }
            }
        }
        return maxRes;
    }
};

 
