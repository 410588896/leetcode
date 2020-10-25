/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

/*******************************************
* 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
*  
* 
* Example 1:
* 
* Input: n = 3
* Output: ["((()))","(()())","(())()","()(())","()()()"]
* Example 2:
* 
* Input: n = 1
* Output: ["()"]
*  
* 
* Constraints:
* 
* 1 <= n <= 8
* 
*******************************************/

// @lc code=start
class Solution {
private:
    void backtrace(vector<string> &res, string &cur, int left, int right, int n) {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (left < n) {
            cur.push_back('(');
            backtrace(res, cur, left + 1, right, n);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            backtrace(res, cur, left, right + 1, n);
            cur.pop_back();
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        backtrace(res, current, 0, 0, n);
        return res;
    }
};
// @lc code=end


