/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> count1, count2;
        for (int num : target) {
            count1[num]++;
        }
        for (int num : arr) {
            count2[num]++;
        }
        if (count1.size() != count2.size()) {
            return false;
        }
        for (auto &[key, value] : count1) {
            if (count2[key] != value) return false;
        }
        return true;
    }
};
// @lc code=end


