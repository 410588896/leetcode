/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

/******************************************
* 
* Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
* 
*  
* 
* Example 1:
* 
* 
* Input: n = 3
* Output: [[1,2,3],[8,9,4],[7,6,5]]
* Example 2:
* 
* Input: n = 1
* Output: [[1]]
*  
* 
* Constraints:
* 
* 1 <= n <= 20
* 
******************************************/

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n - 1, t = 0, b = n - 1;
        vector<vector<int> > res(n, vector<int>(n));
        int num = 1, fin = n * n;
        while (num <= fin) {
            for (int i = l; i <= r; i++) res[t][i] = num++;
            t++;
            for (int i = t; i <= b; i++) res[i][r] = num++;
            r--;
            for (int i = r; i >= l; i--) res[b][i] = num++;
            b--;
            for (int i = b; i >= t; i--) res[i][l] = num++;
            l++;
        }
        return res;
    }
};
// @lc code=end


