/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

/******************************************
* 
* Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
* 
* A word is a maximal substring consisting of non-space characters only.
* 
*  
* 
* Example 1:
* 
* Input: s = "Hello World"
* Output: 5
* Example 2:
* 
* Input: s = " "
* Output: 0
*  
* 
* Constraints:
* 
* 1 <= s.length <= 104
* s consists of only English letters and spaces ' '.
* 
******************************************/

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        while(n >= 0 && s[n] == ' ') n--;
        if (n < 0) return 0;
        int start = n;
        while (start >= 0 && s[start] != ' ')  start--;
        return n - start;
    }
};
// @lc code=end


