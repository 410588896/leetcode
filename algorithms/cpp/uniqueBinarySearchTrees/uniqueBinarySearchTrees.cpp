/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

/****************************************
* 
* Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
* 
* Example:
* 
* Input: 3
* Output: 5
* Explanation:
* Given n = 3, there are a total of 5 unique BST's:
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
*  
* 
* Constraints:
* 
* 1 <= n <= 19
* 
****************************************/

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
// @lc code=end


