/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

/********************************************
* 
* Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,1,2]
* Output:
* [[1,1,2],
*  [1,2,1],
*  [2,1,1]]
* Example 2:
* 
* Input: nums = [1,2,3]
* Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 8
* -10 <= nums[i] <= 10
* 
********************************************/

// @lc code=start
class Solution {
private:
    vector<int> vis;
    void backtrack(vector<int> &nums, vector<vector<int> > &res, int idx, vector<int> &output) {
        if (nums.size() == idx) {
            res.push_back(output);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) continue;
            output.push_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, res, idx + 1, output);
            vis[i] = 0;
            output.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> output;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0, output);
        return res;
    }
};
// @lc code=end


