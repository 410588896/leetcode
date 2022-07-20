/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<string> res;
        while (i < n) {
            int low = nums[i];
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = nums[i - 1];
            if (low < high) {
                res.push_back(to_string(low)+"->"+to_string(high));
            } else {
                res.push_back(to_string(low));
            }
        }
        return res;
    }
};
// @lc code=end


