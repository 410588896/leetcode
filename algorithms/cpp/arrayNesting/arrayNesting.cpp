/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        vector<bool> vis(len, false);
        int res = 0;
        for (int i = 0; i < len ; i++) {
            int cnt = 0;
            while(!vis[i]) {
                vis[i] = true;
                i = nums[i];
                cnt ++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end


