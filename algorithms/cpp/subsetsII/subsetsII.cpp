/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

/***************************************
* 
* Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
* 
* Note: The solution set must not contain duplicate subsets.
* 
* Example:
* 
* Input: [1,2,2]
* Output:
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
* 
***************************************/

// @lc code=start
class Solution {
private:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(int start, const vector<int> &nums, vector<bool> &used) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(i + 1, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        res.clear();
        path.clear();
        if (n == 0) return res;
        vector<bool> used(n, false);
        sort(nums.begin(), nums.end());
        backtracking(0, nums, used);
        return res;
    }
};
// @lc code=end


