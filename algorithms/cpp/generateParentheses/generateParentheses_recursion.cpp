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
    shared_ptr<vector<string>> cache[100] = {nullptr};
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr) return cache[n];
        if (n == 0) cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts) {
                    for (const string& right : *rights) {
                        result->push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = result;
        }
        return cache[n]; 
    }

public:
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};
// @lc code=end


