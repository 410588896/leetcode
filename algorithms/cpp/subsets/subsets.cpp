/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

/******************************************
* 
* Given an integer array nums, return all possible subsets (the power set).
* 
* The solution set must not contain duplicate subsets.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,2,3]
* Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
* Example 2:
* 
* Input: nums = [0]
* Output: [[],[0]]
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 10
* -10 <= nums[i] <= 10
* 
******************************************/

// @lc code=start
class Solution {
private:
    vector<int> tmp;
    vector<vector<int> > res;
    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(tmp);   
            return;
        }
        tmp.push_back(nums[cur]);
        dfs(cur + 1, nums);
        tmp.pop_back();
        dfs(cur + 1, nums);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
// @lc code=end


