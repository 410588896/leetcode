/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

/**************************************
* 
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* You may return the answer in any order.
* 
*  
* 
* Example 1:
* 
* Input: n = 4, k = 2
* Output:
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
* Example 2:
* 
* Input: n = 1, k = 1
* Output: [[1]]
*  
* 
* Constraints:
* 
* 1 <= n <= 20
* 1 <= k <= n
* 
**************************************/

// @lc code=start
class Solution {
private:
    vector<vector<int> > res;
    vector<int> tmp;
    void dfs(int cur, int n, int k) {
        if (tmp.size() + n - cur + 1 < k) return;
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k);
        tmp.pop_back();
        dfs(cur + 1, n, k);
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};
// @lc code=end


