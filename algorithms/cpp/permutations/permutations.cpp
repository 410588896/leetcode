/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

/******************************************
* 
* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,2,3]
* Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
* Example 2:
* 
* Input: nums = [0,1]
* Output: [[0,1],[1,0]]
* Example 3:
* 
* Input: nums = [1]
* Output: [[1]]
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* All the integers of nums are unique.
* 
******************************************/

// @lc code=start
class Solution {
private:
    void backtrack(vector<vector<int> > &res, vector<int> &output, int first, int len) {
        if (first == len) {
            res.push_back(output);
            return;
        }
        for (int i = first; i < len; i++) {
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
// @lc code=end


