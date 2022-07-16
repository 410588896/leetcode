/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            if (mp.count(num) && i - mp[num] <= k) {
                return true;
            }
            mp[num] = i;
        }
        return false;
    }
};
// @lc code=end


