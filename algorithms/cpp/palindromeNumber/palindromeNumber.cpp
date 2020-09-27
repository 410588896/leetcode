/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

/****************************************************
*
* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
* 
* Example 1:
* 
* Input: 121
* Output: true
* Example 2:
* 
* Input: -121
* Output: false
* Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
* Example 3:
* 
* Input: 10
* Output: false
* Explanation: Reads 01 from right to left. Therefore it is not a palindrome
* 
*****************************************************/

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x >= 10) return false;
        int forward = x, backward = 0;
        while (forward > backward) {
            backward = backward * 10 + forward % 10;
            forward = forward / 10;
        }
        if (backward == forward || (backward / 10 == forward)) return true;
        else return false;
    }
};
// @lc code=end


