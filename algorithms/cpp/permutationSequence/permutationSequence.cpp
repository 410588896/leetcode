/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

/*************************************
* 
* The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* Given n and k, return the kth permutation sequence.
* 
*  
* 
* Example 1:
* 
* Input: n = 3, k = 3
* Output: "213"
* Example 2:
* 
* Input: n = 4, k = 9
* Output: "2314"
* Example 3:
* 
* Input: n = 3, k = 1
* Output: "123"
*  
* 
* Constraints:
* 
* 1 <= n <= 9
* 1 <= k <= n!
* 
*************************************/

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        string res;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; j++) {
                order -= valid[j];
                if (!order) {
                    res += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return res;
    }
};
// @lc code=end


