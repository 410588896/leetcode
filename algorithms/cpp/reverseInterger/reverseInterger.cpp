/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

/************************************************
* 
* Given a 32-bit signed integer, reverse digits of an integer.
* 
* Example 1:
* 
* Input: 123
* Output: 321
* Example 2:
* 
* Input: -123
* Output: -321
* Example 3:
* 
* Input: 120
* Output: 21
*
*************************************************/

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            if ((rev > (INT_MAX / 10)) || (rev == (INT_MAX / 10) && pop > 7)) return 0;
            if ((rev < (INT_MIN / 10)) || (rev == (INT_MIN / 10) && pop < -8)) return 0;
            rev = rev * 10 + pop;
            x = x / 10;
        }
        return rev;
    }
};
// @lc code=end

