/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

/*****************************************
* 
* Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
* 
*  
* 
* Example 1:
* 
* Input: x = 2.00000, n = 10
* Output: 1024.00000
* Example 2:
* 
* Input: x = 2.10000, n = 3
* Output: 9.26100
* Example 3:
* 
* Input: x = 2.00000, n = -2
* Output: 0.25000
* Explanation: 2-2 = 1/22 = 1/4 = 0.25
*  
* 
* Constraints:
* 
* -100.0 < x < 100.0
* -231 <= n <= 231-1
* -104 <= xn <= 104
* 
*****************************************/

// @lc code=start
class Solution {
private:
    double quickMul(double x, long long N) {
        if (N == 0) return 1.0;
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// @lc code=end


