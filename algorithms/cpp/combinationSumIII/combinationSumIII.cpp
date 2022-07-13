/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
private:
    vector<int> tmp;
    vector<vector<int> > res;
    void dfs(int cur, int n, int k, int sum) {
        if (tmp.size() > k || (tmp.size() + (n - cur + 1)) < k) return;
        if (tmp.size() == k && accumulate(tmp.begin(), tmp.end(), 0) == sum) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        tmp.pop_back();
        dfs(cur + 1, n, k, sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return res;
    }
};
// @lc code=end


