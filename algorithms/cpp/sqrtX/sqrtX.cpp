/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

/***************************************
* 
* Given a non-negative integer x, compute and return the square root of x.
* 
* Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
* 
*  
* 
* Example 1:
* 
* Input: x = 4
* Output: 2
* Example 2:
* 
* Input: x = 8
* Output: 2
* Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
*  
* 
* Constraints:
* 
* 0 <= x <= 231 - 1
* 
***************************************/
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end


