/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

/****************************************
* 
* Count the number of prime numbers less than a non-negative number, n.
* 
*  
* 
* Example 1:
* 
* Input: n = 10
* Output: 4
* Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
* Example 2:
* 
* Input: n = 0
* Output: 0
* Example 3:
* 
* Input: n = 1
* Output: 0
*  
* 
* Constraints:
* 
* 0 <= n <= 5 * 106
* 
****************************************/

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                res++;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


