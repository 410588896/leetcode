/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

/***************************************************
* 
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 
* An input string is valid if:
* 
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
*  
* 
* Example 1:
* 
* Input: s = "()"
* Output: true
* Example 2:
* 
* Input: s = "()[]{}"
* Output: true
* Example 3:
* 
* Input: s = "(]"
* Output: false
* Example 4:
* 
* Input: s = "([)]"
* Output: false
* Example 5:
* 
* Input: s = "{[]}"
* Output: true
*  
* 
* Constraints:
* 
* 1 <= s.length <= 104
* s consists of parentheses only '()[]{}'.
* 
***************************************************/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 0) return true;
        if (n % 2 == 1) {
            return false;
        }
        unordered_map<char, char> symbols = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> container;
        for (auto item : s) {
            if (symbols.count(item)) {
                if (container.empty() || container.top() != symbols[item]) return false;
                container.pop();
            } else {
                container.push(item);
            }
        }
        return container.empty();
    }
};


